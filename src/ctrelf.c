#include <ctrelf.h>

#include <string.h>

unsigned long elf_hash(const unsigned char *name)
{
	unsigned long h = 0, g;
	while (*name)
	{
		h = (h << 4) + *name++;
		if ((g = h & 0xF000000u))
			h ^= g >> 24u;
		h &= ~g;
	}
	return h;
}

#define ELF_COPY_HDR(elem) memcpy(&header->elem, buffer, sizeof(header->elem)); buffer += sizeof(header->elem);
void elf_load_header(Elf32_Ehdr *header, const void *data)
{
	const char *buffer = data;
	memcpy(header->e_ident, buffer, EI_NIDENT);
	buffer += EI_NIDENT;
	ELF_COPY_HDR(e_type);
	ELF_COPY_HDR(e_machine);
	ELF_COPY_HDR(e_version);
	ELF_COPY_HDR(e_entry);
	ELF_COPY_HDR(e_phoff);
	ELF_COPY_HDR(e_shoff);
	ELF_COPY_HDR(e_flags);
	ELF_COPY_HDR(e_ehsize);
	ELF_COPY_HDR(e_phentsize);
	ELF_COPY_HDR(e_phnum);
	ELF_COPY_HDR(e_shentsize);
	ELF_COPY_HDR(e_shnum);
	ELF_COPY_HDR(e_shstrndx);
}

void elf_load_sheader(Elf32_Shdr *header, const void *data)
{
	const char *buffer = data;
	
	ELF_COPY_HDR(sh_name);
	ELF_COPY_HDR(sh_type);
	ELF_COPY_HDR(sh_flags);
	ELF_COPY_HDR(sh_addr);
	ELF_COPY_HDR(sh_offset);
	ELF_COPY_HDR(sh_size);
	ELF_COPY_HDR(sh_link);
	ELF_COPY_HDR(sh_info);
	ELF_COPY_HDR(sh_addralign);
	ELF_COPY_HDR(sh_entsize);
}

void elf_load_cheader(Elf32_Chdr *header, const void *data)
{
	const char *buffer = data;
	
	ELF_COPY_HDR(ch_type);
	ELF_COPY_HDR(ch_size);
	ELF_COPY_HDR(chaddralign);
}

void elf_load_symbol_table(Elf32_Sym *table, const void *data)
{
	Elf32_Sym *header = table;
	const char *buffer = data;

	ELF_COPY_HDR(st_name);
	ELF_COPY_HDR(st_value);
	ELF_COPY_HDR(st_size);
	ELF_COPY_HDR(st_info);
	ELF_COPY_HDR(st_other);
	ELF_COPY_HDR(st_shndx);
}

void elf_load_rel_entry(Elf32_Rel *entry, const void *data)
{
	Elf32_Rel *header = entry;
	const char *buffer = data;

	ELF_COPY_HDR(r_offset);
	ELF_COPY_HDR(r_info);
}

void elf_load_rela_entry(Elf32_Rela *entry, const void *data)
{
	Elf32_Rela *header = entry;
	const char *buffer = data;

	ELF_COPY_HDR(r_offset);
	ELF_COPY_HDR(r_info);
	ELF_COPY_HDR(r_addend);
}

void elf_load_program_header(Elf32_Phdr *header, const void *data)
{
	const char *buffer = data;
	ELF_COPY_HDR(p_type);
	ELF_COPY_HDR(p_offset);
	ELF_COPY_HDR(p_vaddr);
	ELF_COPY_HDR(p_paddr);
	ELF_COPY_HDR(p_filesz);
	ELF_COPY_HDR(p_memsz);
	ELF_COPY_HDR(p_flags);
	ELF_COPY_HDR(p_align);
}

void elf_load_dyn_entry(Elf32_Dyn *entry, const void *data)
{
	Elf32_Dyn *header = entry;
	const char *buffer = data;
	ELF_COPY_HDR(d_tag);
	switch(header->d_tag)
	{
		case DT_NEEDED:
		case DT_PLTRELSZ:
		case DT_RELASZ:
		case DT_RELAENT:
		case DT_STRSZ:
		case DT_SYMENT:
		case DT_SONAME:
		case DT_RPATH:
		case DT_RELSZ:
		case DT_RELENT:
		case DT_PLTREL:
		case DT_INIT_ARRAYSZ:
		case DT_FINI_ARRAYSZ:
		case DT_RUNPATH:
		case DT_FLAGS:
		case DT_PREINIT_ARRAYSZ:
			ELF_COPY_HDR(d_un.d_val);
			break;

		case DT_PLTGOT:
		case DT_HASH:
		case DT_STRTAB:
		case DT_SYMTAB:
		case DT_RELA:
		case DT_INIT:
		case DT_FINI:
		case DT_REL:
		case DT_DEBUG:
		case DT_JMPREL:
		case DT_INIT_ARRAY:
		case DT_FINI_ARRAY:
		case DT_PREINIT_ARRAY:
		case DT_SYMTAB_SHNDX:
			ELF_COPY_HDR(d_un.d_ptr);
			break;

		default:
			break;
	}
}


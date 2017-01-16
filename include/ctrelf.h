#ifndef CTRELF_H_

#define CTRELF_H_

#include <stdint.h>

typedef uint32_t Elf32_Addr;
typedef uint16_t Elf32_Half;
typedef uint32_t Elf32_Off;
typedef int32_t Elf32_Sword;
typedef uint32_t Elf32_Word;

//e_ident
#define EI_MAG0       (0u)
#define EI_MAG1       (1u)
#define EI_MAG2       (2u)
#define EI_MAG3       (3u)
#define EI_CLASS      (4u)
#define EI_DATA       (5u)
#define EI_VERSION    (6u)
#define EI_OSABI      (7u)
#define EI_ABIVERSION (8u)
#define EI_PAD        (9u)
#define EI_NIDENT     (16u)

//EI_OSABI
#define ELFOSABI_NONE      (0u)
#define ELFOSABI_ARM_AEABI (64u)

//EI_CLASS
#define ELFCLASSNONE (0u)
#define ELFCLASS32   (1u)
#define ELFCLASS64   (2u)

//EI_DATA
#define ELFDATANONE (0u)
#define ELFDATA2LSB (1u)
#define ELFDATA2MSB (2u)

//e_type
#define ET_NONE   (0u)
#define ET_REL    (1u)
#define ET_EXEC   (2u)
#define ET_DYN    (3u)
#define ET_CORE   (4u)
#define ET_LOOS   (0xFE00u)
#define ET_HIOS   (0xFEFFu)
#define ET_LOPROC (0xFF00u)
#define ET_HIPROC (0xFFFFu)

//e_machine
#define EM_NONE (0u)
#define EM_ARM  (40u)

//e_version
#define EV_NONE    (0u)
#define EV_CURRENT (1u)

//ARM e_flags
#define EF_ARM_ABIMASK        (0xFF000000u)
#define EF_ARM_BE8            (0x00800000u)
#define EF_ARM_GCCMASK        (0x00400FFFu)
#define EF_ARM_ABI_FLOAT_HARD (0x00000400u) //EF_ARM_VFP_FLOAT in pre 5 gcc
#define EF_ARM_ABI_FLOAT_SOFT (0x00000200u)

typedef struct
{
	unsigned char e_ident[EI_NIDENT];
	Elf32_Half e_type;
	Elf32_Half e_machine;
	Elf32_Word e_version;
	Elf32_Addr e_entry;
	Elf32_Off e_phoff;
	Elf32_Off e_shoff;
	Elf32_Word e_flags;
	Elf32_Half e_ehsize;
	Elf32_Half e_phentsize;
	Elf32_Half e_phnum;
	Elf32_Half e_shentsize;
	Elf32_Half e_shnum;
	Elf32_Half e_shstrndx;
} Elf32_Ehdr;

//Sections
#define SHN_UNDEF     (0u)
#define SHN_LORESERVE (0xFF00u)
#define SHN_LOPROC    (0xFF00u)
#define SHN_HIPROC    (0xFF1Fu)
#define SHN_LOOS      (0xFF20u)
#define SHN_HIOS      (0xFF3Fu)
#define SHN_ABS       (0xFFF1u)
#define SHN_COMMON    (0xFFF2u)
#define SHN_HIRESERVE (0xFFFFu)

//sh_type
#define SHT_NULL          (0u)
#define SHT_PROGBITS      (1u)
#define SHT_SYMTAB        (3u)
#define SHT_STRTAB        (4u)
#define SHT_HASH          (5u)
#define SHT_DYNAMIC       (6u)
#define SHT_NOTE          (7u)
#define SHT_NOBITS        (8u)
#define SHT_REL           (9u)
#define SHT_SHLIB         (10u)
#define SHT_DYNSYM        (11u)
#define SHT_INIT_ARRAY    (14u)
#define SHT_FINI_ARRAY    (15u)
#define SHT_PREINIT_ARRAY (16u)
#define SHT_GROUP         (17u)
#define SHT_SYMTAB_SHNDX  (18u)
#define SHT_LOOS          (0x60000000u)
#define SHT_HIOS          (0x6FFFFFFFu)
#define SHT_LOPROC        (0x70000000u)

#define SHT_ARM_EXIDX          (0x70000001u)
#define SHT_ARM_PREEMPTMAP     (0x70000002u)
#define SHT_ARM_ATTRIBUTES     (0x70000003u)
#define SHT_ARM_DEBUGOVERLAY   (0x70000004u)
#define SHT_ARM_OVERLAYSECTION (0x70000005u)

#define SHT_HIPROC        (0x7FFFFFFFu)
#define SHT_LOUSER        (0x80000000u)
#define SHT_HIUSER        (0xFFFFFFFFu)

//sh_flags
#define SHF_WRITE            (0x1u)
#define SHF_ALLOC            (0x2u)
#define SHF_EXECINSTR        (0x4u)
#define SHF_MERGE            (0x10u)
#define SHF_STRINGS          (0x20u)
#define SHF_INFO_LINK        (0x40u)
#define SHF_LINK_ORDER       (0x80u)
#define SHF_OS_NONCONFORMING (0x100u)
#define SHF_GROUP            (0x200u)
#define SHF_TLS              (0x400u)
#define SHF_COMPRESSED       (0x800u)
#define SHF_MASKOS           (0x0FF00000u)
#define SHF_MASKPROC         (0xF0000000u)
#define SHF_ARM_NOREAD       (0x20000000u)

typedef struct
{
	Elf32_Word sh_name;
	Elf32_Word sh_type;
	Elf32_Word sh_flags;
	Elf32_Addr sh_addr;
	Elf32_Off sh_offset;
	Elf32_Word sh_size;
	Elf32_Word sh_link;
	Elf32_Word sh_info;
	Elf32_Word sh_addralign;
	Elf32_Word sh_entsize;
} Elf32_Shdr;

typedef struct
{
	Elf32_Word ch_type;
	Elf32_Word ch_size;
	Elf32_Word chaddralign;
} Elf32_Chdr;

//ch_type
#define ELFCOMPRESS_ZLIB   (1u)
#define ELFCOMPRESS_LOOS   (0x60000000u)
#define ELFCOMPRESS_HIOS   (0x6FFFFFFFu)
#define ELFCOMPRESS_LOPROC (0x70000000u)
#define ELFCOMPRESS_HIPROC (0x7FFFFFFFu)

//Section groups
#define GRP_COMDAT   (0x1u)
#define GRP_MASKOS   (0x0FF00000u)
#define GRP_MASKPROC (0xF0000000u)

//Symbol Table
#define STN_UNDEF (0u)

#define ELF32_ST_BIND(i) ((i)>>4u)
#define ELF32_ST_TYPE(i) ((i)&0xFu)
#define ELF32_ST_INFO(b,t) (((b)<<4)+((t)&0xF))

#define ELF32_ST_VISIBILITY(o) ((o)&0x3u)

//ELF32_ST_BIND
#define STB_LOCAL  (0u)
#define STB_GLOBAL (1u)
#define STB_WEAK   (2u)
#define STB_LOOS   (10u)
#define STB_HIOS   (12u)
#define STB_LOPROC (13u)
#define STB_HIPROC (15u)

//ELF32_ST_TYPE
#define STT_NOTYPE  (0u)
#define STT_OBJECT  (1u)
#define STT_FUNC    (2u)
#define STT_SECTION (3u)
#define STT_FILE    (4u)
#define STT_COMMON  (5u)
#define STT_TLS     (6u)
#define STT_LOOS    (10u)
#define STT_HIOS    (12u)
#define STT_LOPROC  (13u)
#define STT_HIPROC  (15u)

//ELF32_ST_VISIBILITY
#define STV_DEFAULT   (0u)
#define STV_INTERNAL  (1u)
#define STV_HIDDEN    (2u)
#define STV_PROTECTED (3u)

typedef struct
{
	Elf32_Word st_name;
	Elf32_Addr st_value;
	Elf32_Word st_size;
	unsigned char st_info;
	unsigned char st_other;
	Elf32_Half st_shndx;
} Elf32_Sym;


//Relocation

#define ELF32_R_SYM(i) ((i)>>8)
#define ELF32_R_TYPE(i) ((unsigned char)(i))
#define ELF32_R_INFO(s,t) (((s)<<8)+(unsigned char)(t))

typedef struct
{
	Elf32_Addr r_offset;
	Elf32_Word r_info;
} Elf32_Rel;

typedef struct
{
	Elf32_Addr r_offset;
	Elf32_Word r_info;
	Elf32_Sword r_addend;
} Elf32_Rela;

#define R_ARM_NONE               (0u)
#define R_ARM_PC24               (1u)
#define R_ARM_ABS32              (2u)
#define R_ARM_REL32              (3u)
#define R_ARM_LDR_PC_G0          (4u)
#define R_ARM_ABS16              (5u)
#define R_ARM_ABS12              (6u)
#define R_ARM_THM_ABS5           (7u)
#define R_ARM_ABS8               (8u)
#define R_ARM_SBREL32            (9u)
#define R_ARM_THM_CALL           (10u)
#define R_ARM_THM_PC8            (11u)
#define R_ARM_BREL_ADJ           (12u)
#define R_ARM_TLS_DESC           (13u)
#define R_ARM_THM_SWI8           (14u)
#define R_ARM_XPC25              (15u)
#define R_ARM_THM_XPC22          (16u)
#define R_ARM_TLS_DTPMOD32       (17u)
#define R_ARM_TLS_DTPOFF32       (18u)
#define R_ARM_TLS_TPOFF32        (19u)
#define R_ARM_TLS_COPY           (20u)
#define R_ARM_GLOB_DAT           (21u)
#define R_ARM_JUMP_SLOT          (22u)
#define R_ARM_RELATIVE           (23u)
#define R_ARM_GOTOFF32           (24u)
#define R_ARM_BASE_PREL          (25u)
#define R_ARM_GOT_BREL           (26u)
#define R_ARM_PLT32              (27u)
#define R_ARM_CALL               (28u)
#define R_ARM_JUMP24             (29u)
#define R_ARM_THM_JUMP24         (30u)
#define R_ARM_BASE_ABS           (31u)
#define R_ARM_ALU_PCREL_7_0      (32u)
#define R_ARM_ALU_PCREL_15_8     (33u)
#define R_ARM_ALU_PCREL_23_15    (34u)
#define R_ARM_LDR_SBREL_11_0_NC  (35u)
#define R_ARM_LDR_SBREL_19_12_NC (36u)
#define R_ARM_LDR_SBREL_27_20_NC (37u)
#define R_ARM_TARGET1            (38u)
#define R_ARM_SBREL21            (39u)
#define R_ARM_V4BX               (40u)
#define R_ARM_TARGET2            (41u)
#define R_ARM_PREL31             (42u)
#define R_ARM_MOVW_ABS_NC        (43u)
#define R_ARM_MOVT_ABS           (44u)
#define R_ARM_MOVW_PREL_NC       (45u)
#define R_ARM_MOVT_PREL          (46u)
#define R_ARM_THM_MOVW_ABS_NC    (47u)
#define R_ARM_THM_MOVT_ABS       (48u)
#define R_ARM_THM_MOVW_PREL_NC   (49u)
#define R_ARM_THM_MOVW_PREL      (50u)
#define R_ARM_THM_JUMP19         (51u)
#define R_ARM_THM_JUMP6          (52u)
#define R_ARM_THM_ALU_PREL_11_0  (53u)
#define R_ARM_THM_PC12           (54u)
#define R_ARM_ABS32_NOI          (55u)
#define R_ARM_REL32_NOI          (56u)
#define R_ARM_ALU_PC_G0_NC       (57u)
#define R_ARM_ALU_PC_G0          (58u)
#define R_ARM_ALU_PC_G1_NC       (59u)
#define R_ARM_ALU_PC_G1          (60u)
#define R_ARM_ALU_PC_G2          (61u)
#define R_ARM_LDR_PC_G1          (62u)
#define R_ARM_LDR_PC_G2          (63u)
#define R_ARM_LDRS_PC_G0         (64u)
#define R_ARM_LDRS_PC_G1         (65u)
#define R_ARM_LDRS_PC_G2         (66u)
#define R_ARM_LDC_PC_G0          (67u)
#define R_ARM_LDC_PC_G1          (68u)
#define R_ARM_LDC_PC_G2          (69u)
#define R_ARM_ALU_SB_G0_NC       (70u)
#define R_ARM_ALU_SB_G0          (71u)
#define R_ARM_ALU_SB_G1_NC       (72u)
#define R_ARM_ALU_SB_G1          (73u)
#define R_ARM_ALU_SB_G2          (74u)
#define R_ARM_LDR_SB_G0          (75u)
#define R_ARM_LDR_SB_G1          (76u)
#define R_ARM_LDR_SB_G2          (77u)
#define R_ARM_LDRS_SB_G0         (78u)
#define R_ARM_LDRS_SB_G1         (79u)
#define R_ARM_LDRS_SB_G2         (80u)
#define R_ARM_LDC_SB_G0          (81u)
#define R_ARM_LDC_SB_G1          (82u)
#define R_ARM_LDC_SB_G2          (83u)
#define R_ARM_MOVW_BREL_NC       (84u)
#define R_ARM_MOVT_BREL          (85u)
#define R_ARM_MOVW_BREL          (86u)
#define R_ARM_THM_MOVW_BREL_NC   (87u)
#define R_ARM_THM_MOVT_BREL      (88u)
#define R_ARM_THM_MOVW_BREL      (89u)
#define R_ARM_TLS_GOTDESC        (90u)
#define R_ARM_TLS_CALL           (91u)
#define R_ARM_TLS_DESCSEQ        (92u)
#define R_ARM_THM_TLS_CALL       (93u)
#define R_ARM_PLT32_ABS          (94u)
#define R_ARM_GOT_ABS            (95u)
#define R_ARM_GOT_PREL           (96u)
#define R_ARM_GOT_BREL12         (97u)
#define R_ARM_GOTOFF12           (98u)
#define R_ARM_GOTRELAX           (99u)
#define R_ARM_GNU_VTENTRY        (100u)
#define R_ARM_GNU_VTINHERIT      (101u)
#define R_ARM_THM_JUMP11         (102u)
#define R_ARM_THM_JUMP8          (103u)
#define R_ARM_TLS_GD32           (104u)
#define R_ARM_TLS_LDM32          (105u)
#define R_ARM_TLS_LDO32          (106u)
#define R_ARM_TLS_IE32           (107u)
#define R_ARM_TLS_LE32           (108u)
#define R_ARM_TLS_LDO12          (109u)
#define R_ARM_TLS_LE12           (110u)
#define R_ARM_TLS_IE12GP         (111u)
#define R_ARM_PRIVATE_(n)        ((0xFu&n) + 112u)
#define R_ARM_ME_TOO             (128u)
#define R_ARM_THM_TLS_DESCSEQ16  (129u)
#define R_ARM_THM_TLS_DESCSEQ32  (130u)
#define R_ARM_THM_GOT_BREL12     (131u)
#define R_ARM_THM_ALU_ABS_G0_NC  (132u)
#define R_ARM_THM_ALU_ABS_G1_NC  (133u)
#define R_ARM_THM_ALU_ABS_G2_NC  (134u)
#define R_ARM_THM_ALU_ABS_G3     (135u)
#define R_ARM_IRELATIVE          (160u)

//Program header

#define PT_NULL        (0u)
#define PT_LOAD        (1u)
#define PT_DYNAMIC     (2u)
#define PT_INTERP      (3u)
#define PT_NOTE        (4u)
#define PT_SHLIB       (5u)
#define PT_PHDR        (6u)
#define PT_TLS         (7u)
#define PT_LOOS        (0x60000000u)
#define PT_HIOS        (0x6FFFFFFFu)
#define PT_LOPROC      (0x70000000u)
#define PT_HIPROC      (0x7FFFFFFFu)
#define PT_ARM_ARCHEXT (0x70000000u)
#define PT_ARM_EXIDX    (0x70000001u)
#define PT_ARM_UNDWIND (0x70000001u)

//Platform architecture compatibility data
#define PT_ARM_ARCHEXT_FMTMSK  (0xFF000000u)
#define PT_ARM_ARCHEXT_PROFMSK (0x00FF0000u)
#define PT_ARM_ARCHEXT_ARCHMSK (0x000000FFu)
#define PT_ARM_ARCHEXT_FMT_OS  (0x00000000u)
#define PT_ARM_ARCHEXT_FMT_ABI (0x01000000u)

#define PT_ARM_ARCHEXT_PROF_NONE    (0x00000000u)
#define PT_ARM_ARCHEXT_PROF_ARM     (0x00410000u)
#define PT_ARM_ARCHEXT_PROF_RT      (0x00520000u)
#define PT_ARM_ARCHEXT_PROF_MC      (0x004D0000u)
#define PT_ARM_ARCHEXT_PROF_CLASSIC (0x00530000)

#define PT_ARM_ARCHEXT_ARCH_UNKN (0x00u)
#define PT_ARM_ARCHEXT_ARCHv4    (0x01u)
#define PT_ARM_ARCHEXT_ARCHv4T   (0x02u)
#define PT_ARM_ARCHEXT_ARCHv5T   (0x03u)
#define PT_ARM_ARCHEXT_ARCHv5TE  (0x04u)
#define PT_ARM_ARCHEXT_ARCHv5TEJ (0x05u)
#define PT_ARM_ARCHEXT_ARCHv6    (0x06u)
#define PT_ARM_ARCHEXT_ARCHv6KZ  (0x07u)
#define PT_ARM_ARCHEXT_ARCHv6T2  (0x08u)
#define PT_ARM_ARCHEXT_ARCHv6K   (0x09u)
#define PT_ARM_ARCHEXT_ARCHv7    (0x0Au)
#define PT_ARM_ARCHEXT_ARCHv6M   (0x0Bu)
#define PT_ARM_ARCHEXT_ARCHv6SM  (0x0Cu)
#define PT_ARM_ARCHEXT_ARCHv7EM  (0x0Du)

#define PF_X        (0x1u)
#define PF_W        (0x2u)
#define PF_R        (0x4u)
#define PF_MASKOS   (0x0FF00000u)
#define PF_MASKPROC (0xF0000000u)

typedef struct
{
	Elf32_Word p_type;
	Elf32_Off p_offset;
	Elf32_Addr p_vaddr;
	Elf32_Addr p_paddr;
	Elf32_Word p_filesz;
	Elf32_Word p_memsz;
	Elf32_Word p_flags;
	Elf32_Word p_align;
} Elf32_Phdr;

//Dynamic linking

#define DT_NULL            (0u)
#define DT_NEEDED          (1u)
#define DT_PLTRELSZ        (2u)
#define DT_PLTGOT          (3u)
#define DT_HASH            (4u)
#define DT_STRTAB          (5u)
#define DT_SYMTAB          (6u)
#define DT_RELA            (7u)
#define DT_RELASZ          (8u)
#define DT_RELAENT         (9u)
#define DT_STRSZ           (10u)
#define DT_SYMENT          (11u)
#define DT_INIT            (12u)
#define DT_FINI            (13u)
#define DT_SONAME          (14u)
#define DT_RPATH           (15u)
#define DT_SYMBOLIC        (16u)
#define DT_REL             (17u)
#define DT_RELSZ           (18u)
#define DT_RELENT          (19u)
#define DT_PLTREL          (20u)
#define DT_DEBUG           (21u)
#define DT_TEXTREL         (22u)
#define DT_JMPREL          (23u)
#define DT_BIND_NOW        (24u)
#define DT_INIT_ARRAY      (25u)
#define DT_FINI_ARRAY      (26u)
#define DT_INIT_ARRAYSZ    (27u)
#define DT_FINI_ARRAYSZ    (28u)
#define DT_RUNPATH         (29u)
#define DT_FLAGS           (30u)
#define DT_ENCODING        (32u)
#define DT_PREINIT_ARRAY   (32u)
#define DT_PREINIT_ARRAYSZ (33u)
#define DT_SYMTAB_SHNDX    (34u)
#define DT_LOOS            (0x6000000Du)
#define DT_HIOS            (0x6FFFF000u)
#define DT_LOPROC          (0x70000000u)
#define DT_HIPROC          (0x7FFFFFFFu)
#define DR_ARM_RESERVED1   (0x70000000u)
#define DR_ARM_SYMTABSZ    (0x70000001u)
#define DR_ARM_PREEMPTMAP  (0x70000002u)
#define DR_ARM_RESERVED2   (0x70000003u)

#define DF_ORIGIN     (0x1u)
#define DF_SYMBOLIC   (0x2u)
#define DF_TEXTREL    (0x4u)
#define DF_BIND_NOW   (0x8u)
#define DF_STATIC_TLS (0x10u)

typedef struct
{
	Elf32_Sword d_tag;
	union
	{
		Elf32_Word d_val;
		Elf32_Addr d_ptr;
	} d_un;
} Elf32_Dyn;

extern Elf32_Dyn _DYNAMIC[];

unsigned long elf_hash(const unsigned char *name);
void elf_load_header(Elf32_Ehdr *header, const void *data);
void elf_load_sheader(Elf32_Shdr *header, const void *data);
void elf_load_cheader(Elf32_Chdr *header, const void *data);
void elf_load_symbol_table(Elf32_Sym *table, const void *data);
void elf_load_rel_entry(Elf32_Rel *entry, const void *data);
void elf_load_rela_entry(Elf32_Rela *entry, const void *data);
void elf_load_program_header(Elf32_Phdr *header, const void *data);
void elf_load_dyn_entry(Elf32_Dyn *entry, const void *data);



#endif//CTRELF_H_


#ifndef SSZipCommon
#define SSZipCommon

/* tm_unz contain date/time info */
typedef struct tm_unz_s
{
    uInt tm_sec;                /* seconds after the minute - [0,59] */
    uInt tm_min;                /* minutes after the hour - [0,59] */
    uInt tm_hour;               /* hours since midnight - [0,23] */
    uInt tm_mday;               /* day of the month - [1,31] */
    uInt tm_mon;                /* months since January - [0,11] */
    uInt tm_year;               /* years - [1980..2044] */
} tm_unz;

typedef struct unz_file_info_s
{
    uLong version;              /* version made by                 2 bytes */
    uLong version_needed;       /* version needed to extract       2 bytes */
    uLong flag;                 /* general purpose bit flag        2 bytes */
    uLong compression_method;   /* compression method              2 bytes */
    uLong dosDate;              /* last mod file date in Dos fmt   4 bytes */
    uLong crc;                  /* crc-32                          4 bytes */
    uLong compressed_size;      /* compressed size                 4 bytes */
    uLong uncompressed_size;    /* uncompressed size               4 bytes */
    uLong size_filename;        /* filename length                 2 bytes */
    uLong size_file_extra;      /* extra field length              2 bytes */
    uLong size_file_comment;    /* file comment length             2 bytes */
    
    uLong disk_num_start;       /* disk number start               2 bytes */
    uLong internal_fa;          /* internal file attributes        2 bytes */
    uLong external_fa;          /* external file attributes        4 bytes */
    
    tm_unz tmu_date;
    uLong disk_offset;
} unz_file_info;

/* unz_file_info contain information about a file in the zipfile */
typedef struct unz_file_info64_s
{
    uLong version;              /* version made by                 2 bytes */
    uLong version_needed;       /* version needed to extract       2 bytes */
    uLong flag;                 /* general purpose bit flag        2 bytes */
    uLong compression_method;   /* compression method              2 bytes */
    uLong dosDate;              /* last mod file date in Dos fmt   4 bytes */
    uLong crc;                  /* crc-32                          4 bytes */
    ZPOS64_T compressed_size;   /* compressed size                 8 bytes */
    ZPOS64_T uncompressed_size; /* uncompressed size               8 bytes */
    uLong size_filename;        /* filename length                 2 bytes */
    uLong size_file_extra;      /* extra field length              2 bytes */
    uLong size_file_comment;    /* file comment length             2 bytes */
    
    uLong disk_num_start;       /* disk number start               2 bytes */
    uLong internal_fa;          /* internal file attributes        2 bytes */
    uLong external_fa;          /* external file attributes        4 bytes */
    
    tm_unz tmu_date;
    ZPOS64_T disk_offset;
    uLong size_file_extra_internal;
} unz_file_info64;

typedef struct unz_global_info_s
{
    uLong number_entry;         /* total number of entries in the central dir on this disk */
    uLong number_disk_with_CD;  /* number the the disk with central dir, used for spanning ZIP*/
    uLong size_comment;         /* size of the global comment of the zipfile */
} unz_global_info;

/* unz_global_info structure contain global data about the ZIPfile
 These data comes from the end of central dir */
typedef struct unz_global_info64_s
{
    ZPOS64_T number_entry;      /* total number of entries in the central dir on this disk */
    uLong number_disk_with_CD;  /* number the the disk with central dir, used for spanning ZIP*/
    uLong size_comment;         /* size of the global comment of the zipfile */
} unz_global_info64;


#endif

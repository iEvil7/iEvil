//TaskTransform.h

#pragma pack(1)

typedef enum _STREAM_OPERATE_
{
    OPT_UNKOWN = 0,
    OPT_IMG_DEPLOY,
    OPT_IMG_LOAD,
    OPT_IMG_DELETE,
    OPT_IMG_CLONE,
    OPT_IMG_COPY,
    OPT_TEMP_CREATE,
    OPT_BOOT_OS,
    OPT_POWER_OFF,
    OPT_POWER_ON,
    OPT_REBOOT,
    OPT_ENUM_TEMP,
    OPT_ENUM_VM,
    OPT_TAKE_SNAPSHOT,
    OPT_REVERT_SNAPSHOT,
    OPT_ENUM_SNAPSHOT,
    OPT_TEMP_DELETE,
    OPT_DELETE_SNAPSHOT,
}STREAM_OPERATE;

typedef enum _PARTITION_TYPE_
{
    PART_TYPE_UNKNOWN = 0,
    PART_TYPE_OS,
    PART_TYPE_DATA,
}PARTITION_TYPE;

typedef struct _POLICY_INFOR_ 
{
    
}POLICY_INFOR, *PPOLICY_INFOR;

typedef struct _IMG_SNAPSHOT_
{
    char cName[32];
    char cTime[20];
}IMG_SNAPSHOT, *PIMG_SNAPSHOT;

typedef struct _PARTITION_INFOR_
{
    PARTITION_TYPE Type;
    DDWORD i64Size;
    char cName[32];
    char cUUID[64];
    IMG_SNAPSHOT Snapshot[2];
}PARTITION_INFOR, *PPARTITION_INFOR;

typedef struct _IMG_INFOR_
{
    DDWORD i64Sectors;
    char cName[32];
    char cPath[128];
    char cNFSPath[64];
    char cURI[128];
    DDWORD i64DiskSectors;
    char cDiskGUID[37];
    char cSysInfor[100];
    char cUUID[64];
    int iPartCount;
    PPARTITION_INFOR pPartInfo;
}IMG_INFOR, *PIMG_INFOR;

typedef struct _USER_INFOR_
{
    char cName[32];
    char cPassword[32];
}USER_INFOR, *PUSER_INFOR;

typedef struct _CLIENT_INFOR_
{
    char cMac[20];
}CLIENT_INFOR, *PCLIENT_INFOR;

typedef struct _TASK_INFOR_
{
    int iNumber;
    int iResult;
    STREAM_OPERATE iOperation;
    CLIENT_INFOR ClientInfo;
    USER_INFOR User;    //if user not null, img for user, otherwise for client
    int iImgCount;
    int iPolicyCount;
    PIMG_INFOR pImgInfo;
    PPOLICY_INFOR pPolicy;
}TASK_INFOR, *PTASK_INFOR;

#pragma pack()

//把TASK_INFOR结构转换成char *
void SetTaskInBuffer(IN PTASK_INFOR pTask, OUT char **pcBuffer, OUT int *piBufSize);
//把char*指针数据转换成TASK_INFOR结构
void GetTaskFromBuffer(IN char *pcBuffer, IN int iBufSize, IN PTASK_INFOR pTask);
//打印输出TASK_INFOR结构
void PrintTaskInfo(IN PTASK_INFOR pTask);

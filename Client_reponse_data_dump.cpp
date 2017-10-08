#include "Client_reponse_data_dump.h"
register_data_dump_fun Client_reponse_data_dump::m_register_data_dump_fun_array[]={
	{"dump_reponse_main_01_VOLUMES", 		&Client_reponse_data_dump::dump_reponse_main_01_VOLUMES,		01, 0},
	{"dump_reponse_main_02_SERVERNAME", 		&Client_reponse_data_dump::dump_reponse_main_02_SERVERNAME,		02, 0},
	{"dump_reponse_main_03_INTERNAL_NETWORK", 		&Client_reponse_data_dump::dump_reponse_main_03_INTERNAL_NETWORK,		03, 0},
	{"dump_reponse_main_04_IPX_DEVICES", 		&Client_reponse_data_dump::dump_reponse_main_04_IPX_DEVICES,		04, 0},
	{"dump_reponse_main_05_SPECIAL_DEVICEC_FLAGS", 		&Client_reponse_data_dump::dump_reponse_main_05_SPECIAL_DEVICEC_FLAGS,		05, 0},
	{"dump_reponse_main_06_VERSION_SPOOFING", 		&Client_reponse_data_dump::dump_reponse_main_06_VERSION_SPOOFING,		06, 0},
	{"dump_reponse_main_07_PASSWORD_HANDLEING", 		&Client_reponse_data_dump::dump_reponse_main_07_PASSWORD_HANDLEING,		07, 0},
	{"dump_reponse_main_08_NOT_USING", 		&Client_reponse_data_dump::dump_reponse_main_08_NOT_USING,		8, 0},
	{"dump_reponse_main_09_CREATE_MODE", 		&Client_reponse_data_dump::dump_reponse_main_09_CREATE_MODE,		9, 0},
	{"dump_reponse_main_10_UID_RIGHTS", 		&Client_reponse_data_dump::dump_reponse_main_10_UID_RIGHTS,		10, 0},
	{"dump_reponse_main_11_GID_RIGHTS", 		&Client_reponse_data_dump::dump_reponse_main_11_GID_RIGHTS,		11, 0},
	{"dump_reponse_main_12_SUPERVISOR_LOGIN", 		&Client_reponse_data_dump::dump_reponse_main_12_SUPERVISOR_LOGIN,		12, 0},
	{"dump_reponse_main_13_USER_LOGIN", 		&Client_reponse_data_dump::dump_reponse_main_13_USER_LOGIN,		13, 0},
	{"dump_reponse_main_14_NOT_USING_14", 		&Client_reponse_data_dump::dump_reponse_main_14_NOT_USING_14,		14, 0},
	{"dump_reponse_main_15_MAPPING_OF_LOGINS", 		&Client_reponse_data_dump::dump_reponse_main_15_MAPPING_OF_LOGINS,		15, 0},
	{"dump_reponse_main_16_TESTS_ON_STARTUP", 		&Client_reponse_data_dump::dump_reponse_main_16_TESTS_ON_STARTUP,		16, 0},
	{"dump_reponse_main_21_NO_SUMMARY_21", 		&Client_reponse_data_dump::dump_reponse_main_21_NO_SUMMARY_21,		21, 0},
	{"dump_reponse_main_22_NO_SUMMARY_22", 		&Client_reponse_data_dump::dump_reponse_main_22_NO_SUMMARY_22,		22, 0},
	{"dump_reponse_main_31_NO_SUMMARY_31", 		&Client_reponse_data_dump::dump_reponse_main_31_NO_SUMMARY_31,		31, 0},
	{"dump_reponse_main_40_NO_SUMMARY_40", 		&Client_reponse_data_dump::dump_reponse_main_40_NO_SUMMARY_40,		40, 0},
	{"dump_reponse_main_41_NO_SUMMARY_41", 		&Client_reponse_data_dump::dump_reponse_main_41_NO_SUMMARY_41,		41, 0},
	{"dump_reponse_main_42_NO_SUMMARY_42", 		&Client_reponse_data_dump::dump_reponse_main_42_NO_SUMMARY_42,		42, 0},
	{"dump_reponse_main_45_NO_SUMMARY_45", 		&Client_reponse_data_dump::dump_reponse_main_45_NO_SUMMARY_45,		45, 0},
	{"dump_reponse_main_46_NO_SUMMARY_46", 		&Client_reponse_data_dump::dump_reponse_main_46_NO_SUMMARY_46,		46, 0},
	{"dump_reponse_main_47_NO_SUMMARY_47", 		&Client_reponse_data_dump::dump_reponse_main_47_NO_SUMMARY_47,		47, 0},
	{"dump_reponse_main_100_NO_SUMMARY_100", 		&Client_reponse_data_dump::dump_reponse_main_100_NO_SUMMARY_100,		100, 0},
	{"dump_reponse_main_101_NO_SUMMARY_101", 		&Client_reponse_data_dump::dump_reponse_main_101_NO_SUMMARY_101,		101, 0},
	{"dump_reponse_main_102_NO_SUMMARY_102", 		&Client_reponse_data_dump::dump_reponse_main_102_NO_SUMMARY_102,		102, 0},
	{"dump_reponse_main_103_NO_SUMMARY_103", 		&Client_reponse_data_dump::dump_reponse_main_103_NO_SUMMARY_103,		103, 0},
	{"dump_reponse_main_104_NO_SUMMARY_104", 		&Client_reponse_data_dump::dump_reponse_main_104_NO_SUMMARY_104,		104, 0},
	{"dump_reponse_main_105_NO_SUMMARY_105", 		&Client_reponse_data_dump::dump_reponse_main_105_NO_SUMMARY_105,		105, 0},
	{"dump_reponse_main_106_NO_SUMMARY_106", 		&Client_reponse_data_dump::dump_reponse_main_106_NO_SUMMARY_106,		106, 0},
	{"dump_reponse_main_200_NO_SUMMARY_200", 		&Client_reponse_data_dump::dump_reponse_main_200_NO_SUMMARY_200,		200, 0},
	{"dump_reponse_main_201_NO_SUMMARY_201", 		&Client_reponse_data_dump::dump_reponse_main_201_NO_SUMMARY_201,		201, 0},
	{"dump_reponse_main_202_NO_SUMMARY_202", 		&Client_reponse_data_dump::dump_reponse_main_202_NO_SUMMARY_202,		202, 0},
	{"dump_reponse_main_210_NO_SUMMARY_210", 		&Client_reponse_data_dump::dump_reponse_main_210_NO_SUMMARY_210,		210, 0},
	{"dump_reponse_main_211_NO_SUMMARY_211", 		&Client_reponse_data_dump::dump_reponse_main_211_NO_SUMMARY_211,		211, 0},
	{"dump_reponse_main_300_NO_SUMMARY_300", 		&Client_reponse_data_dump::dump_reponse_main_300_NO_SUMMARY_300,		300, 0},
	{"dump_reponse_main_301_NO_SUMMARY_301", 		&Client_reponse_data_dump::dump_reponse_main_301_NO_SUMMARY_301,		301, 0},
	{"dump_reponse_main_302_NO_SUMMARY_302", 		&Client_reponse_data_dump::dump_reponse_main_302_NO_SUMMARY_302,		302, 0},
	{"dump_reponse_main_310_NO_SUMMARY_310", 		&Client_reponse_data_dump::dump_reponse_main_310_NO_SUMMARY_310,		310, 0},
	{"dump_reponse_main_400_NO_SUMMARY_400", 		&Client_reponse_data_dump::dump_reponse_main_400_NO_SUMMARY_400,		400, 0},
	{"dump_reponse_main_401_NO_SUMMARY_401", 		&Client_reponse_data_dump::dump_reponse_main_401_NO_SUMMARY_401,		401, 0},
	{"dump_reponse_main_402_NO_SUMMARY_402", 		&Client_reponse_data_dump::dump_reponse_main_402_NO_SUMMARY_402,		402, 0},
	{"dump_reponse_main_501_GET_STATION_LIST", 		&Client_reponse_data_dump::dump_reponse_main_501_GET_STATION_LIST,		501, 0},
	{"dump_reponse_main_502_NOTIFY_STATION_LOGIN", 		&Client_reponse_data_dump::dump_reponse_main_502_NOTIFY_STATION_LOGIN,		502, 0},
	{"dump_reponse_main_503_NOTIFY_STATION_LOGOUT", 		&Client_reponse_data_dump::dump_reponse_main_503_NOTIFY_STATION_LOGOUT,		503, 0},
	{"dump_reponse_main_504_NOTIFY_NWCONN_EXITING", 		&Client_reponse_data_dump::dump_reponse_main_504_NOTIFY_NWCONN_EXITING,		504, 0},
	{"dump_reponse_main_505_KILL_NWCONN", 		&Client_reponse_data_dump::dump_reponse_main_505_KILL_NWCONN,		505, 0},
	{"dump_reponse_main_506_CURRENT_ACCESS_FILE", 		&Client_reponse_data_dump::dump_reponse_main_506_CURRENT_ACCESS_FILE,		506, 0},
	{"dump_reponse_main_507_START_NWSERV", 		&Client_reponse_data_dump::dump_reponse_main_507_START_NWSERV,		507, 0},
	{"dump_reponse_main_508_STOP_NWSERV", 		&Client_reponse_data_dump::dump_reponse_main_508_STOP_NWSERV,		508, 0},
	{"dump_reponse_main_509_RESTART_NWSERV", 		&Client_reponse_data_dump::dump_reponse_main_509_RESTART_NWSERV,		509, 0},
	{"dump_reponse_main_510_REFRESH_ALL", 		&Client_reponse_data_dump::dump_reponse_main_510_REFRESH_ALL,		510, 0},
	{"dump_reponse_main_511_GET_LOG", 		&Client_reponse_data_dump::dump_reponse_main_511_GET_LOG,		511, 0},
	{"dump_reponse_main_512_WHO_USE_THIS_FILE", 		&Client_reponse_data_dump::dump_reponse_main_512_WHO_USE_THIS_FILE,		512, 0},
	{"dump_reponse_main_513_GEN_CORE_DUMP", 		&Client_reponse_data_dump::dump_reponse_main_513_GEN_CORE_DUMP,		513, 0},
        {{0}, NULL, 0, 0}
    };
int Client_reponse_data_dump::dump_reponse_main_01_VOLUMES(char *data, int data_len)
{
	cout<<"call "<<__FUNCTION__<<endl;
	return 1;
};


int Client_reponse_data_dump::dump_reponse_main_02_SERVERNAME(char *data, int data_len)
{
	cout<<"call "<<__FUNCTION__<<endl;
	return 1;
};


int Client_reponse_data_dump::dump_reponse_main_03_INTERNAL_NETWORK(char *data, int data_len)
{
	cout<<"call "<<__FUNCTION__<<endl;
	return 1;
};


int Client_reponse_data_dump::dump_reponse_main_04_IPX_DEVICES(char *data, int data_len)
{
	cout<<"call "<<__FUNCTION__<<endl;
	return 1;
};


int Client_reponse_data_dump::dump_reponse_main_05_SPECIAL_DEVICEC_FLAGS(char *data, int data_len)
{
	cout<<"call "<<__FUNCTION__<<endl;
	return 1;
};


int Client_reponse_data_dump::dump_reponse_main_06_VERSION_SPOOFING(char *data, int data_len)
{
	cout<<"call "<<__FUNCTION__<<endl;
	return 1;
};


int Client_reponse_data_dump::dump_reponse_main_07_PASSWORD_HANDLEING(char *data, int data_len)
{
	cout<<"call "<<__FUNCTION__<<endl;
	return 1;
};


int Client_reponse_data_dump::dump_reponse_main_08_NOT_USING(char *data, int data_len)
{
	cout<<"call "<<__FUNCTION__<<endl;
	return 1;
};


int Client_reponse_data_dump::dump_reponse_main_09_CREATE_MODE(char *data, int data_len)
{
	cout<<"call "<<__FUNCTION__<<endl;
	return 1;
};


int Client_reponse_data_dump::dump_reponse_main_10_UID_RIGHTS(char *data, int data_len)
{
	cout<<"call "<<__FUNCTION__<<endl;
	return 1;
};


int Client_reponse_data_dump::dump_reponse_main_11_GID_RIGHTS(char *data, int data_len)
{
	cout<<"call "<<__FUNCTION__<<endl;
	return 1;
};


int Client_reponse_data_dump::dump_reponse_main_12_SUPERVISOR_LOGIN(char *data, int data_len)
{
	cout<<"call "<<__FUNCTION__<<endl;
	return 1;
};


int Client_reponse_data_dump::dump_reponse_main_13_USER_LOGIN(char *data, int data_len)
{
	cout<<"call "<<__FUNCTION__<<endl;
	return 1;
};


int Client_reponse_data_dump::dump_reponse_main_14_NOT_USING_14(char *data, int data_len)
{
	cout<<"call "<<__FUNCTION__<<endl;
	return 1;
};


int Client_reponse_data_dump::dump_reponse_main_15_MAPPING_OF_LOGINS(char *data, int data_len)
{
	cout<<"call "<<__FUNCTION__<<endl;
	return 1;
};


int Client_reponse_data_dump::dump_reponse_main_16_TESTS_ON_STARTUP(char *data, int data_len)
{
	cout<<"call "<<__FUNCTION__<<endl;
	return 1;
};


int Client_reponse_data_dump::dump_reponse_main_21_NO_SUMMARY_21(char *data, int data_len)
{
	cout<<"call "<<__FUNCTION__<<endl;
	return 1;
};


int Client_reponse_data_dump::dump_reponse_main_22_NO_SUMMARY_22(char *data, int data_len)
{
	cout<<"call "<<__FUNCTION__<<endl;
	return 1;
};


int Client_reponse_data_dump::dump_reponse_main_31_NO_SUMMARY_31(char *data, int data_len)
{
	cout<<"call "<<__FUNCTION__<<endl;
	return 1;
};


int Client_reponse_data_dump::dump_reponse_main_40_NO_SUMMARY_40(char *data, int data_len)
{
	cout<<"call "<<__FUNCTION__<<endl;
	return 1;
};


int Client_reponse_data_dump::dump_reponse_main_41_NO_SUMMARY_41(char *data, int data_len)
{
	cout<<"call "<<__FUNCTION__<<endl;
	return 1;
};


int Client_reponse_data_dump::dump_reponse_main_42_NO_SUMMARY_42(char *data, int data_len)
{
	cout<<"call "<<__FUNCTION__<<endl;
	return 1;
};


int Client_reponse_data_dump::dump_reponse_main_45_NO_SUMMARY_45(char *data, int data_len)
{
	cout<<"call "<<__FUNCTION__<<endl;
	return 1;
};


int Client_reponse_data_dump::dump_reponse_main_46_NO_SUMMARY_46(char *data, int data_len)
{
	cout<<"call "<<__FUNCTION__<<endl;
	return 1;
};


int Client_reponse_data_dump::dump_reponse_main_47_NO_SUMMARY_47(char *data, int data_len)
{
	cout<<"call "<<__FUNCTION__<<endl;
	return 1;
};


int Client_reponse_data_dump::dump_reponse_main_100_NO_SUMMARY_100(char *data, int data_len)
{
	cout<<"call "<<__FUNCTION__<<endl;
	return 1;
};


int Client_reponse_data_dump::dump_reponse_main_101_NO_SUMMARY_101(char *data, int data_len)
{
	cout<<"call "<<__FUNCTION__<<endl;
	return 1;
};


int Client_reponse_data_dump::dump_reponse_main_102_NO_SUMMARY_102(char *data, int data_len)
{
	cout<<"call "<<__FUNCTION__<<endl;
	return 1;
};


int Client_reponse_data_dump::dump_reponse_main_103_NO_SUMMARY_103(char *data, int data_len)
{
	cout<<"call "<<__FUNCTION__<<endl;
	return 1;
};


int Client_reponse_data_dump::dump_reponse_main_104_NO_SUMMARY_104(char *data, int data_len)
{
	cout<<"call "<<__FUNCTION__<<endl;
	return 1;
};


int Client_reponse_data_dump::dump_reponse_main_105_NO_SUMMARY_105(char *data, int data_len)
{
	cout<<"call "<<__FUNCTION__<<endl;
	return 1;
};


int Client_reponse_data_dump::dump_reponse_main_106_NO_SUMMARY_106(char *data, int data_len)
{
	cout<<"call "<<__FUNCTION__<<endl;
	return 1;
};


int Client_reponse_data_dump::dump_reponse_main_200_NO_SUMMARY_200(char *data, int data_len)
{
	cout<<"call "<<__FUNCTION__<<endl;
	return 1;
};


int Client_reponse_data_dump::dump_reponse_main_201_NO_SUMMARY_201(char *data, int data_len)
{
	cout<<"call "<<__FUNCTION__<<endl;
	return 1;
};


int Client_reponse_data_dump::dump_reponse_main_202_NO_SUMMARY_202(char *data, int data_len)
{
	cout<<"call "<<__FUNCTION__<<endl;
	return 1;
};


int Client_reponse_data_dump::dump_reponse_main_210_NO_SUMMARY_210(char *data, int data_len)
{
	cout<<"call "<<__FUNCTION__<<endl;
	return 1;
};


int Client_reponse_data_dump::dump_reponse_main_211_NO_SUMMARY_211(char *data, int data_len)
{
	cout<<"call "<<__FUNCTION__<<endl;
	return 1;
};


int Client_reponse_data_dump::dump_reponse_main_300_NO_SUMMARY_300(char *data, int data_len)
{
	cout<<"call "<<__FUNCTION__<<endl;
	return 1;
};


int Client_reponse_data_dump::dump_reponse_main_301_NO_SUMMARY_301(char *data, int data_len)
{
	cout<<"call "<<__FUNCTION__<<endl;
	return 1;
};


int Client_reponse_data_dump::dump_reponse_main_302_NO_SUMMARY_302(char *data, int data_len)
{
	cout<<"call "<<__FUNCTION__<<endl;
	return 1;
};


int Client_reponse_data_dump::dump_reponse_main_310_NO_SUMMARY_310(char *data, int data_len)
{
	cout<<"call "<<__FUNCTION__<<endl;
	return 1;
};


int Client_reponse_data_dump::dump_reponse_main_400_NO_SUMMARY_400(char *data, int data_len)
{
	cout<<"call "<<__FUNCTION__<<endl;
	return 1;
};


int Client_reponse_data_dump::dump_reponse_main_401_NO_SUMMARY_401(char *data, int data_len)
{
	cout<<"call "<<__FUNCTION__<<endl;
	return 1;
};


int Client_reponse_data_dump::dump_reponse_main_402_NO_SUMMARY_402(char *data, int data_len)
{
	cout<<"call "<<__FUNCTION__<<endl;
	return 1;
};


int Client_reponse_data_dump::dump_reponse_main_501_GET_STATION_LIST(char *data, int data_len)
{
	cout<<"call "<<__FUNCTION__<<endl;
	return 1;
};


int Client_reponse_data_dump::dump_reponse_main_502_NOTIFY_STATION_LOGIN(char *data, int data_len)
{
	cout<<"call "<<__FUNCTION__<<endl;
	return 1;
};


int Client_reponse_data_dump::dump_reponse_main_503_NOTIFY_STATION_LOGOUT(char *data, int data_len)
{
	cout<<"call "<<__FUNCTION__<<endl;
	return 1;
};


int Client_reponse_data_dump::dump_reponse_main_504_NOTIFY_NWCONN_EXITING(char *data, int data_len)
{
	cout<<"call "<<__FUNCTION__<<endl;
	return 1;
};


int Client_reponse_data_dump::dump_reponse_main_505_KILL_NWCONN(char *data, int data_len)
{
	cout<<"call "<<__FUNCTION__<<endl;
	return 1;
};


int Client_reponse_data_dump::dump_reponse_main_506_CURRENT_ACCESS_FILE(char *data, int data_len)
{
	cout<<"call "<<__FUNCTION__<<endl;
	return 1;
};


int Client_reponse_data_dump::dump_reponse_main_507_START_NWSERV(char *data, int data_len)
{
	cout<<"call "<<__FUNCTION__<<endl;
	return 1;
};


int Client_reponse_data_dump::dump_reponse_main_508_STOP_NWSERV(char *data, int data_len)
{
	cout<<"call "<<__FUNCTION__<<endl;
	return 1;
};


int Client_reponse_data_dump::dump_reponse_main_509_RESTART_NWSERV(char *data, int data_len)
{
	cout<<"call "<<__FUNCTION__<<endl;
	return 1;
};


int Client_reponse_data_dump::dump_reponse_main_510_REFRESH_ALL(char *data, int data_len)
{
	cout<<"call "<<__FUNCTION__<<endl;
	return 1;
};


int Client_reponse_data_dump::dump_reponse_main_511_GET_LOG(char *data, int data_len)
{
	cout<<"call "<<__FUNCTION__<<endl;
	return 1;
};


int Client_reponse_data_dump::dump_reponse_main_512_WHO_USE_THIS_FILE(char *data, int data_len)
{
	cout<<"call "<<__FUNCTION__<<endl;
	return 1;
};


int Client_reponse_data_dump::dump_reponse_main_513_GEN_CORE_DUMP(char *data, int data_len)
{
	cout<<"call "<<__FUNCTION__<<endl;
	return 1;
};


/****************************************************************************
* Description    根据main_function 和 sub_function  找到对应的dispatch 的函数. 
* @param    
* @return   
****************************************************************************/
data_dump_fun Client_reponse_data_dump::find_function(unsigned long main, unsigned long sub)
{
//m_register_data_dump_fun_array
    int count=(sizeof( m_register_data_dump_fun_array)/sizeof(m_register_data_dump_fun_array[0]));
    for(int i=0; i< count; i++)
    {
        if(m_register_data_dump_fun_array[i].main_function== main )
//&& 
//              m_register_data_dump_fun_array[i].sub_function ==sub)
        {
            return  m_register_data_dump_fun_array[i].fun;

        }
    }
    return NULL;
}
int Client_reponse_data_dump::dispatch(char *data, int length)
{
    REQUEST * request = (REQUEST*)data;

    data_dump_fun   process=NULL;
    if(request->size != (unsigned int )length)
    {
        log::Instance()->logger("长度不符合: header.size = %d, length = %d\n",
            request->size, length);
        printf(" 长度不符合\n");
    }

    //------------------------------------------------------------------------
    //根据 main sub 查找对应注册的函数. 
    process=find_function(request->main_function, request->sub_function);
    if(process != NULL)
    {
        (this->*process)(data, length);
    }
    else
    {
        log::Instance()->logger("找不到处理函数., size: %d, main: %d, sub: %d\n", request->size, request->main_function, request->sub_function);
        //错误处理. 
        //send error frame 
    }
    return 1;
}
int main() {
Client_reponse_data_dump data_dump;
FRAME frame;
//随机化 FRAME 
//rand_data(frame)
data_dump.dispatch((char*)&frame, frame.header.size);
	return 0; 
;}

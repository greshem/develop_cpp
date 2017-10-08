//########################################################################
#include <fstream>
#include <string> 
#include <iostream>
#include <map>
#include <iostream> 
#include <algorithm>
#include <vector> 
#include <iterator>  
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <dirent.h>

#include "../../data_engine/conf_parser.h"
#include "../../data_engine/conf.cpp"
#include "../../data_engine/IniFile.hpp"
#include "../../data_engine/log.h"
#include "../../data_engine/max_sub_protocol.h"
#include "../../include/protocol.h"
#include "tcp_client_socket.h"
#include "client_protocol_data.h"
#include "Client_reponse_data_dump.h"
#include "../../include//protocol.h"
#include "../../data_engine/data_dict_comment.h"
//#include "../../include/struct_dump_type.h"

using namespace std;
int main(int argc, char *argv[])
{
	unsigned long main_function=0;
	unsigned long sub_function=0;
	char item[64]={0};
	max_sub_protocol m_max_sub;
	CConfFile conf("output.conf");
	// nw_conf_parser conf; //д�ļ�
	//if(1 == conf.parse_file(string("output.conf")))
	//{
	//	cout<<"output.conf�ļ��򿪳ɹ�"<<endl;
	//}
	conf.parse_file();
	cmd_args client_opts;
	memset(&client_opts, '\0', sizeof(cmd_args));
	func_data_process_ptr do_request;
	
//------------------------------------------------------------------------
	//��ʼ.
	Client test;
	Client_reponse_data_dump  data_dump;

	FRAME frame;
	if(do_request !=NULL)
	{
		if(test.init()< 0)
		{
			printf("����, ��ʼ��ʧ�� �� �����˳�\n");
			exit(-1);
		}

		for(main_function=1; main_function<=402; main_function++)
		{
			unsigned long max_sub = m_max_sub.getMax(main_function);
			for(sub_function=0; sub_function <= max_sub; sub_function++)
			{
				printf("main_fun %ld sub_fun %ld \n ", main_function, sub_function);		
				do_request = test.find_function(main_function, sub_function);		
				if(NULL == do_request)
				{
					break;
				}
				client_opts.main_function = main_function;
				client_opts.sub_function = sub_function;

				(test.*do_request)((char *)&client_opts, sizeof(client_opts)); //����. 
				while(test.is_readable() > 0)
				{
					log::Instance()->logger("���յ���һ����\n");
					printf ("���յ���һ����\n");
					int ret=0, err = 0;
					ret=test.recv_one_frame(frame);
					{
						memset(item, '\0', sizeof(item));
						char *data = (char*)&frame;

					//	err = data_dump.dispatch_to_dump((char*)&frame, ret );	
						strncpy(item,data+sizeof(REQUEST)+sizeof(tagResult),sizeof(item));
						printf("%s\n", item);
						conf.add_item(main_function, sub_function, item);
					}
					if(ret<0)
					{
						break;
					}
					if (0 == err)
						break;
				}
			}//�ڶ���for
			//conf.save_file_with_comment(string("output.conf"));
			conf.save_file(string("output.conf"));
		}
	}
	else
	{
		cout<<"�Ҳ�����Ӧ�������� "<<endl;
		log::Instance()->logger( "�Ҳ�����Ӧ��������\n");
	}
	test.release();
	return 1;
}


    #include <iostream>
    #include <map>
    using namespace std;
    main()
    {
        map<string, int> m;
        m["one"] = 1; //[] Ӧ���ǲ���������.  
        m["two"] = 2;
        // ���ֲ�ͬ��insert���÷���
        m.insert(make_pair("three", 3));
        m.insert(map<string, int>::value_type("four", 4));
        m.insert(pair<string, int>("five", 5));

        string key;
        //while (cin>>key)
        key="one";
        {
            map<string, int>::iterator it = m.find(key);
            if (it==m.end())
            {
                cout << "No such key!" << endl;
            }
            else
            {
                cout << key << " is " << it->second << endl;
                cout << "Erased " << m.erase(key) << endl;
            }
        }
        return 0;
    }


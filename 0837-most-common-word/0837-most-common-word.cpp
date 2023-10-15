class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned)
    {
        // 벡터 하나 생성해서 공백이 생길 때 마다 문자열을 쪼개서 그 벡터에 집어넣는다.
        vector<int> vec_0Idx;
        vector<string> vec_sPara;

        // 공백이 들어있을 때의 인덱스를 집어 넣음.
        for(int i = 0; i< paragraph.length()+2; ++i)
        {
            if('\0' == paragraph[i])
            {
                vec_0Idx.push_back(i);
                break;
            }
            if((' ' == paragraph[i] || ',' == paragraph[i] || '?' == paragraph[i] )
            && ( paragraph[i+1] == ' ' || paragraph[i+1] == ',' || paragraph[i+1] == '?'))
            {
            }
            else if ((' ' == paragraph[i] || ',' == paragraph[i]  || '?' == paragraph[i]))
            {
                vec_0Idx.push_back(i);
            }
        }

        int strLen; // 공백과 다음 공백 사이의 단어의 길이를 알기 위함.
        // 벡터에 공백마다 단어를 잘라 넣음. 모두 소문자로, 특문은 제거함.
        map<string, int> wordCnt;
        for(int i = 0; i < vec_0Idx.size(); ++i)
        {
            string tmp;
            if(0 == i)
            {
                strLen = vec_0Idx[0] - 0;
                //cout << i << "strLen : " << strLen << endl;
                tmp = paragraph.substr(0,vec_0Idx[i]);
            }
            else
            {
                strLen = ( vec_0Idx[i] - vec_0Idx[i-1] )-1;
                //cout << i << "strLen : " << strLen << endl;
                tmp = paragraph.substr(vec_0Idx[i-1]+1,strLen);
            }
            transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
            tmp = regex_replace( tmp , regex("[^a-z0-9]+"), "" );
            vec_sPara.push_back(tmp);

            // 흔한지 판단하기 위해 맵에 페어 넣기
            if (wordCnt.find(tmp) != wordCnt.end()) // 단어가  있다.
            {
                wordCnt[tmp] += 1;
            }
            else // 단어가 없다
            {
                wordCnt.insert(make_pair(tmp,1));
            } 
        }

        // 최고로 흔한 단어가 밴된 단어라면 그 다음으로 흔한 단어를 모스트로 지정.
        pair<string,int> mostPair = {" ", 0};
        string mostWord = mostPair.first;

        //밴 벡터를 돌면서 워드카운트 맵을 돎
        //만약 밴할 단어랑 워드 카운트의 키랑 같으면 밸류를 -1로 처리.

        for(int i = 0; i < banned.size(); ++i)
        {
            for(map<string,int>::iterator it = wordCnt.begin(); it != wordCnt.end(); ++it)
            {
                if(it->first == banned[i])
                {
                    it->second = -1;
                }
            }
        }

        for(map<string,int>::iterator it = wordCnt.begin(); it != wordCnt.end(); ++it)
        {
            if(it->second > mostPair.second) 
            {
                if(banned.empty()) // 밴 할 게 없다면
                {
                    mostPair = {it->first, it->second};
                    mostWord = it->first;
                }
                else // 밴 할 게 있다면
                {
                    for(int i = 0; i < banned.size(); ++i)
                    {
                            mostPair = {it->first, it->second};
                            mostWord = it->first;
                    }

                }
                
            }      
        }        

        // --------------------------------------------------------------
        // return값 바꿔주기.
        cout << "------------------------------------------" << endl;
        cout << "paragraph : " << paragraph << endl;
        for(int i = 0; i < vec_0Idx.size(); ++i)
        {
            cout << "vec_0Idx[" << i <<"] : " << vec_0Idx[i] << endl;
        }
        for(int i = 0; i < vec_sPara.size(); ++i)
        {
            cout << "vec_sPara[" << i <<"] : " << vec_sPara[i] << endl;
        }
        for(map<string,int>::iterator it = wordCnt.begin(); it != wordCnt.end(); ++it)
        {
            cout << it->first << "-" << it->second << endl;
        }

        return mostWord;
    }
};


// 금지된 단어를 제외한 가장 혼하게 동장하는 단어를 출력하라.
// 대소문자 구분을 하지 않으며 구두점 (마침표 쉼표 등) 또한 무시한다.

// paragraph 스트링, banned 스트링 벡터
// 가장 자주 쓰인 단ㅇ너는 banned에 안 들어감.
// 적어도 금지되지 않은 단어가 하나는 있다는 건 보장함.
// 그리고 그 답은 독특함.아니 고유함.. ?
// paragraph에 든 단어들은 대소문자 구분 안 하고, 답은 무조건 소문자로 리턴되어야 함. 특문 다 빼야 할 듯.

            // if(it == wordCnt.begin())
            // {
            //     for(int i = 0; i < banned.size(); ++i)
            //     {
            //         if(it->first == banned[i])
            //             break;
            //     }
            // }
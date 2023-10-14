class Solution 
{
public:
    vector<string> reorderLogFiles(vector<string>& logs) 
    {
        vector<int>logNullIdx;
        logNullIdx.reserve(logs.size());
        int bPushBack = false;
        vector<string> vAlpha;
        vector<string> vDigit;
        int tmpIdx;
        int tmpIdx2;

        vector<string> vAlphaIdf;


        for(int i = 0; i < logs.size(); ++i)
        {
            bPushBack = false;
            for(int j = 0; j <= logs[i].length(); ++j)
            {
                if( ' '== logs[i][j])
                {
                    if(!bPushBack)
                    {
                        logNullIdx[i] = j;
                        bPushBack = true;
                        tmpIdx = logNullIdx[i]; 
                        tmpIdx2 = logNullIdx[i+1];

                        if( isalpha(logs[i][tmpIdx+1])) // 문자냐
                        {
                            vAlpha.push_back(logs[i].substr(tmpIdx+1));
                            vAlphaIdf.push_back(logs[i].substr(0, (tmpIdx)));
                        }
                        else if(isdigit(logs[i][tmpIdx+1]))
                        {
                            vDigit.push_back(logs[i]);
                        }
                    } 
                }
            }
        } 
        
        sort(vAlpha.begin(), vAlpha.end());
        sort(vAlphaIdf.begin(), vAlphaIdf.end());

        int j = 0;
        bool bOrdered = false;

        for(int i = 0; i < vAlpha.size(); ++i)
        {
            j = 0;
            while(true)
            {
                if(j >= logs.size() )
                {
                    break;
                }
                tmpIdx = logNullIdx[j]; 
                

                if ( vAlpha[i] == logs[j].substr(tmpIdx+1) ) // 문자벡터의 요소와 원본벡터의 요소가 같다면
                {

                    if(bOrdered) // 이미 식별자가 붙었다면
                    {
                        vAlpha[i] = logs[j].substr(0, (tmpIdx)) + " " + vAlpha[i];
                        if ( vAlpha[i-1].substr() > logs[j].substr(0, (tmpIdx)) )
                        {
                            swap(vAlpha[i], vAlpha[i-1]);

                            if(i+1 >= vAlpha.size())
                                break;

                            if(vAlpha[i+1] == logs[j].substr(tmpIdx+1)) 
                            { 
                                logs[j] = logs[j] + " "; // 
                                break;
                            }
                            else 
                            { 
                                bOrdered = false; 
                                break;
                            }
                        }
                        break;
                    }

                    else // 처음 식별자가 붙음.
                    {
                        vAlpha[i] = logs[j].substr(0, (tmpIdx)) + " " + vAlpha[i];

                        if(i+1 >= vAlpha.size())
                                break;
                                
                        if(vAlpha[i+1] == logs[j].substr(tmpIdx+1)) 
                        { 
                            bOrdered = true;
                            logs[j] = logs[j] + " "; // 
                            break;
                        }
                        else 
                        { 
                            bOrdered = false; 
                            break;
                        }
                    }
                }
                else ++j;
                              
            }



             // for(int j = 0; j < logs.size(); ++j)
            // {
            //     tmpIdx = logNullIdx[j]; 
            //     //cout << logs[j].substr(tmpIdx+1) << endl;
            //     if ( vAlpha[i] == logs[j].substr(tmpIdx+1) )
            //     {
            //         //cout << logs[j].substr(0, (tmpIdx)) + " " + vAlpha[i] << endl;
            //         vAlpha[i] = logs[j].substr(0, (tmpIdx)) + " " + vAlpha[i];
            //     }
            // }

        }

        for(int i = 0; i < vDigit.size(); ++i)
        {
            vAlpha.push_back(vDigit[i]);
        }
            
        return vAlpha;             
    }
};

// log 중복일 때 식별자 기준으로 사전순 재배열 필요.


// 문자 식별자let이 숫자 식별자dig 보다 앞에 있어야 함 
// ㄴ 식별자로는 판별 불가, 식별자에 대한 로그 내용으로 판별해야 한다. 
// 문자 식별자 -> 사전순으로 정렬
// 숫자 식별자 -> 그냥 적힌 순으로 (따로 정렬하지 않음.)

// 1. 문자 식별자, 숫자 식별자 구분해서 정렬 -> 문자 식별자가 앞에, 숫자 식별자가 뒤에
// 2. 문자 식별자들끼라 사전순 정렬
// 2. 숫자 식별자는 냅둠.

// 1. (벡터 하나의 요소를 기준) 띄어쓰기가 나온다면 그 이후 첫 글자가 영어냐 숫자냐 물어봄
// 문자 식별자인지 숫자 식별자인지 구분 가능 -> 숫자면 뒤 인덱스 식별자와 비교, 숫자면 냅둠 문자면 변경


            // if ( isalpha(logs[i][tmpIdx+1]) && isalpha(logs[i+1][tmpIdx2+1]) )// 둘 다 문자
            // {
            //     cout << i << " :  문자, 문자" << endl;
            //     if(logs[i][tmpIdx+1] > logs[i+1][tmpIdx2+1])
            //     {
            //         swap(logs[i] , logs[i+1]);
            //     }
            // }
            // else if ( isdigit(logs[i][tmpIdx+1]) && isdigit(logs[i+1][tmpIdx2+1]) ) // 둘 다 숫자
            // {
            //     cout << i << " :  숫자, 숫자" << endl;
            //     startNumIdx = i;
            // }
            // else if ( isalpha(logs[i][tmpIdx+1]) && isdigit(logs[i+1][tmpIdx2+1]) ) // 앞 문자, 뒤 숫자
            // { 
            //     cout << i << " :  문자, 숫자" << endl;
            //     startNumIdx = i+1;
            // }
            // else if ( isdigit(logs[i][tmpIdx+1]) && isalpha(logs[i+1][tmpIdx2+1]) ) // 앞 숫자, 뒤 문자
            // { 
            //     cout << i << " :  숫자, 문자" << endl;
            //     startNumIdx = i+1;
            //     swap(logs[i] , logs[i+1]);
                
            // }
            // else
            // {
            //     cout << "else : " << i << endl;
            // }
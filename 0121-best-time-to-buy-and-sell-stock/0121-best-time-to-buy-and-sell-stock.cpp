class Solution 
{
public:

// prices 의 인덱스는 인덱스 날짜의 주식 가격임.
// 하루를 선택하여 한 주식을 매수하고,  미래의 다른 날을 선택해 매도 가능.
// 얻을 수 있는 최대 이익을 리턴해라..
// 수익 달성이 안 되면 걍 0 반환.

/*
벡터를 순회하면서 인덱스의 최소값(매수금액)을 찾음. 
그리고 뒤에 있는 값들과 비교해 제일 차이가 큰 값(매도금액)을 알고 그 차이 이득 금액을 저장.
벡터 순회하면서 현재의 최대 이득 금액보다 지금의 이득 금액이 크다면 최대 이득 금액을 변경. 
*/

    int maxProfit(vector<int>& prices) 
     {

        auto buyIter = prices.begin();
        auto sellIter = max_element(prices.begin(), prices.end());
        int profit = 0;

        if(1 == prices.size())
        {
            return 0;
        }

        else if(2 == prices.size())
        {
            cout << "prices.size = 2" << endl;
            profit = prices[0] > prices[1] ? 0 : prices[1] - prices[0]; 
            return profit;
        }

        else
        {
            for(auto iter = prices.begin(); iter != prices.end(); ++iter)
            {
                if(*iter < *buyIter) 
                {
                    buyIter = iter; // 매수 지정

                    // 만약 매수 지점이 매도 지점보다 뒤에 있으면
                    // 매도 지점 변경
                    if(buyIter - prices.begin() > sellIter - prices.begin())
                    {
                        cout << "i'm here"<< endl;
                        sellIter = max_element(buyIter, prices.end());
                    }


                    // if(*sellIter != *(max_element(iter, prices.end())))
                    // {
                    //     sellIter = max_element(iter, prices.end());
                    // }   
                    // cout << "*sellIter : " << *sellIter << endl;

                    if(*sellIter - *iter < 0)
                    {
                        cout << "sellIter : " << *sellIter << endl << endl;
                        return 0;
                    }
                    else if((*sellIter - *iter) > profit)
                    {
                        profit = (*sellIter - *iter);
                        cout << profit << endl;
                    }
                }
                else if(*iter == *buyIter)
                {
                    if(*sellIter - *iter < 0)
                    {
                        cout << "sellIter : " << *sellIter << endl << endl;
                        return 0;
                    }
                    else if((*sellIter - *iter) > profit)
                    {
                        profit = (*sellIter - *iter);
                        cout << profit << endl;
                    }
                }
            }

        }
            // // 최소값에 있는 이터의 인덱스의 값이 엔드의 값과 같다면
                    // if( *(min_element(prices.begin(), prices.end())) == *(prices.end()-1)) 
                    // {
                    //     if(buyIter == min_element(prices.begin(), prices.end()))
                    //     {
                    //     }
                    //     else
                    //     {
                    //     cout << "here...." << endl;
                    //     // 맥스가 내 뒤에 있다면? 이프문 나가야 함.
                    //     if(max_element(prices.begin(), prices.end()) != prices.begin())
                    //     {

                    //     }
                    //     else
                    //     {
                    //         return 0; 
                    //     }   
                    //     }

                    // }

        






    //     int BuyingIdx = 0; //  매수 날짜
    //     int SellingIdx = 0; // 매도 날짜

    //     int profit = prices[SellingIdx] - prices[BuyingIdx]; // 매도금 - 매수금 = 순이익

    //     for(int i = 0; i< prices.size(); ++i)
    //     {
    //         if(prices[i] < prices[BuyingIdx]) // 순회중인 날짜가 예정된 매수 날짜보다 낮은 가격이면
    //         {
    //             BuyingIdx = i; // 매수날을 순회하는 중인 날짜로 바꿈.
    //         }

    //         for(int j = i + 1; j < prices.size(); ++j)
    //         {
    //             if(prices[j] > prices[BuyingIdx]) // 만약 순회중인 날짜가 예정된 매도 날짜보다 높은 가격이면
    //             {
    //                 if(profit < prices[j] - prices[i]) // 예정된 매도 날짜에 대한 이익보다 현재 날짜에 대한 이익이 크면
    //                 {
    //                     profit = prices[j] - prices[i]; // 이익은 순회중인 매도 날짜 - 순회중인 매수 날짜

    //                 }
    //             }
    //         }
    //     }
        return profit;
        
    }
};


        // while( minIdx == (find(prices.begin(),prices.end(), *(prices.end())) - prices.begin() ))
        // {
        //     minIdx = min_element(prices.begin(), prices.end()-i) - prices.begin();
        //     ++i;
        //     cout << minIdx;
        // }

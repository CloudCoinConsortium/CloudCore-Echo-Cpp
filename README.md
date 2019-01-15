# CloudCore Echoer in C++

The job of the Echoer is to see if the RAIDA can be contacted and if the RAIDA is healthy enough to pown coins. The Echoer will also record the results so that other Servants will not waste time contacting RAIDA that are offline.

## Echo Request

**Request**  
GET https://raida1.cloudcoin.global/service/echo  
User-Agent: Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.11 (KHTML, like Gecko) Chrome/23.0.1271.95 Safari/537.11

**Example Response**  
{"server":"RAIDA1","status":"ready","message":"Execution Time (milliseconds) = 0.892","version":"2018-04-25","time":"2019-01-15 00:08:21"}
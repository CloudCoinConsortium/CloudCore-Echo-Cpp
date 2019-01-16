# CloudCore Echoer in C++

The job of the Echoer is to see if the RAIDA can be contacted and if the RAIDA is healthy enough to pown coins. The Echoer will also record the results so that other Servants will not waste time contacting RAIDA that are offline.

The RAIDA class stores all the details that are received from the RAIDA server.

Typically the address of RAIDA servers are: raida0.cloudcoin.global, raida2.cloudcoin.global ... raida24.cloudcoin.global. However the index can be specified in the indexes array.



## Echo Request

**Request**  
GET https://raida1.cloudcoin.global/service/echo  
_Possibly Required:_  
User-Agent: Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.11 (KHTML, like Gecko) Chrome/23.0.1271.95 Safari/537.11

**Example Response**  
{"server":"RAIDA1","status":"ready","message":"Execution Time (milliseconds) = 0.892","version":"2018-04-25","time":"2019-01-15 00:08:21"}

## References
- Cloud Bank: https://github.com/CloudCoinConsortium/CloudBank-V2
- RAIDA Advanced Client
Servant Based Architecture: https://cloudcoinconsortium.org/software.html#echoer
- C++ Style Guide and Naming Conventions: https://gist.github.com/lefticus/10191322
- Makefile: 
	- http://www.hep.lu.se/courses/MNXB01/2017/MNXB01-tutorial-6b.pdf
	- http://www.ecst.csuchico.edu/~trhenry/classes/211.s17/src/p6/Makefile
	- http://webhome.csc.uvic.ca/~sae/seng265/fall04/html/makeexample.html
	- https://www.cs.swarthmore.edu/~newhall/unixhelp/howto_makefiles.html
	- https://www.cs.colostate.edu/~cs157/LectureMakefile.pdf
- How to measure execution time intervals in C++: https://www.pluralsight.com/blog/software-development/how-to-measure-execution-time-intervals-in-c--
- Passing Arguments to Threads: https://courses.engr.illinois.edu/cs241/fa2012/lectures/15-Pthread-Examples.pdf

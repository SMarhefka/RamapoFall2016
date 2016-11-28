/*	
	Lab 1
	Assigned: September 19, 2016
	Due: October 3rd, 2016
	Description: Determine the speed of 8 byte integer and double adds and 
	multiplies on your machine.  You will need the web to find out about how 
	to time the calculations.  Please email me your program and give me 
	your results.  Warning long is 32 bits in Visual Studio. (Unmanaged code)
*/
#include <iostream>
#include <chrono> //chrono::system_clock

using namespace std;
//too many integers
//using nano_seconds = chrono::nanoseconds;
using milli_seconds = chrono::milliseconds;

long long x;
double y;

int main() {

	//TEST 1 - MAIN LOOP TIME 
	//START TIMING
	auto mstart = chrono::system_clock::now();
	for (int count = 0; count < 1000000000; count++)
	{
		x = x + y;
	}
	//STOP TIMING
	auto mend = chrono::system_clock::now();

	//TIME DIFFERENCE BETWEEN START AND END
	auto mtime = mend - mstart;
	cout << "MAIN LOOP: " << chrono::duration_cast<milli_seconds>(mtime).count() << " ms\n" << endl;
	/*=======================================================================*/

	//TEST 1 - 8 BYTE ADDITION
	x = 80003;

	//START TIMING
	auto start1 = chrono::system_clock::now();
	for (int count = 0; count < 1000000000; count++)
	{
		x = x + 53;
	}
	//STOP TIMING
	auto end1 = chrono::system_clock::now();
	
	//TIME DIFFERENCE BETWEEN START AND END
	auto time1 = end1 - start1;
	cout << "8 BYTE ADDITION: " << chrono::duration_cast<milli_seconds>(time1).count() << " ms" << endl;
	/*=======================================================================*/

	//TEST 2 - 8 BYTE MULTIPLICATION
	x = 80003;
	//START TIMING
	auto start2 = chrono::system_clock::now();
	for (int count = 0; count < 1000000000; count++)
	{
		x = x * 53;
	}
	//STOP TIMING
	auto end2 = chrono::system_clock::now();

	//TIME DIFFERENCE BETWEEN START AND END
	auto time2 = end2 - start2;
	cout << "8 BYTE MULTIPLICATION: " << chrono::duration_cast<milli_seconds>(time2).count() << " ms" << endl;
	/*=======================================================================*/

	//TEST 3 - DOUBLE ADDITION
	y = 8003;
	//START TIMING
	auto start3 = chrono::system_clock::now();
	for (int count = 0; count < 1000000000; count++)
	{
		y = y + 53;
	}
	//STOP TIMING
	auto end3 = chrono::system_clock::now();

	//TIME DIFFERENCE BETWEEN START AND END
	auto time3 = end3 - start3;
	cout << "DOUBLE ADDITION: " << chrono::duration_cast<milli_seconds>(time3).count() << " ms" << endl;
	/*=======================================================================*/

	//TEST 4 - DOUBLE MULTIPLICATION
	y = 8003;
	//START TIMING
	auto start4 = chrono::system_clock::now();
	for (int count = 0; count < 1000000000; count++)
	{
		y = y * 53;
	}
	//STOP TIMING
	auto end4 = chrono::system_clock::now();

	//TIME DIFFERENCE BETWEEN START AND END
	auto time4 = end4 - start4;
	cout << "DOUBLE MULTIPLICATION: " << chrono::duration_cast<milli_seconds>(time4).count() << " ms\n" << endl;
	/*=======================================================================*/

	//FINAL TIME 8 BYTE ADDITION = TIME5 - TIME1
	auto eightbyteadd = mtime - time1;
	//FINAL TIME 8 BYTE MULTIPLICATION = TIME5 - TIME2
	auto eightbytemult = mtime - time2;
	//FINAL TIME DOUBLE ADDITION = TIME5 - TIME3
	auto doubleadd = mtime - time3;
	//FINAL TIME DOUBLE MULTIPLICATION = TIME5 - TIME4
	auto doublemult = mtime - time4;

	//PRINT RESULTS
	cout << "8 BYTE ADDITION: " << chrono::duration_cast<milli_seconds>(eightbyteadd).count() << " ms" << endl;
	cout << "DOUBLE ADDITION: " << chrono::duration_cast<milli_seconds>(doubleadd).count() << " ms\n" << endl;
	cout << "8 BYTE MULTIPLICATION: " << chrono::duration_cast<milli_seconds>(eightbytemult).count() << " ms" << endl;
	cout << "DOUBLE MULTIPLICATION: " << chrono::duration_cast<milli_seconds>(doublemult).count() << " ms" << endl;
}

#include<iostream>
#include<thread>
 
void fun() {
	std::cout << "hello thread" << std::endl;
}
 
 
int main() {
 
	std::thread t(fun);
	t.join();
 
	system("pause");
}

#include <iostream>
#include <bitset>

using namespace std;

int main(){
    // data는 1111 1111 1111 1111이며
    // 이때 모든 비트는 1이기 때문에
    // 모든 원소가 존재하는 집합이라고 말할 수 있다.
    unsigned int data = 0xffff;
    cout << bitset<16>(data) << "   data" << endl;
    
    // 두번째 원소 제거하기 
    data = data & ~(1<<1);                                // 집합의 원소를 제거 
    cout << bitset<16>(data) << "   Delete(&~)" << endl;                    // 1111 1111 1111 1101
    
    // 두번째 원소 추가하기 (이미 존재하면 그대로) 
    data = data | (1<<1);            
    cout << bitset<16>(data) << "   Add(|)" << endl;                    // 1111 1111 1111 1111
    
    // 두번째 원소가 포함되어 있는지 검사
    data = data & (1<<1); 
    cout << bitset<16>(data) << "   Check(&)" << endl;                    // 존재하면 > 0, 존재하지 않으면 < 0 
    
    // 두번째 원소를 바꾸기 1 -> 0, 0 -> 1
    data = data ^ (1<<1);
    cout << bitset<16>(data) << "   Change(^)" << endl; 
    
    // 두번째 원소가 포함되어 있는지 검사
    data = data & (1<<1); 
    cout << bitset<16>(data) << "   Check(&)" << endl;                    // 존재하면 > 0, 존재하지 않으면 < 0 
    
    return 0;
}
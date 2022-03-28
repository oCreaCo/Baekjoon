#include <iostream>
//#include <bitset>

using namespace std;

int main(){
    // data?�� 1111 1111 1111 1111?���?
    // ?��?�� 모든 비트?�� 1?���? ?��문에
    // 모든 ?��?���? 존재?��?�� 집합?��?���? 말할 ?�� ?��?��.
    unsigned int data = 0xffff;
    cout << bitset<16>(data) << "   data" << endl;
    
    // ?��번째 ?��?�� ?��거하�? 
    data = data & ~(1<<1);                                
    // 집합?�� ?��?���? ?���? 
    cout << bitset<16>(data) << "   Delete(&~)" << endl;                    
    // 1111 1111 1111 1101
    
    // ?��번째 ?��?�� 추�???���? (?���? 존재?���? 그�??�?) 
    data = data | (1<<1);            
    cout << bitset<16>(data) << "   Add(|)" << endl;                    
    // 1111 1111 1111 1111
    
    // ?��번째 ?��?���? ?��?��?��?�� ?��?���? �??��
    data = data & (1<<1); 
    cout << bitset<16>(data) << "   Check(&)" << endl;                    
    // 존재?���? > 0, 존재?���? ?��?���? < 0 
    
    // ?��번째 ?��?���? 바꾸�? 1 -> 0, 0 -> 1
    data = data ^ (1<<1);
    cout << bitset<16>(data) << "   Change(^)" << endl; 
    
    // ?��번째 ?��?���? ?��?��?��?�� ?��?���? �??��
    data = data & (1<<1); 
    cout << bitset<16>(data) << "   Check(&)" << endl;                    
    // 존재?���? > 0, 존재?���? ?��?���? < 0 
    
    return 0;
}
#include <iostream>
#include <queue>
using namespace std;
 
struct patient
{
    int x;
    int y;
    string name;
    patient(int inX, int inY, string nameS)
    {
        x = inX;
        y = inY;
        name = nameS;
    }
}; 
struct compare
{
    bool operator()(const patient &a, const patient &b)
    {
        //cout<<(a.x > b.x)<<endl;
        if(a.x == b.x)
        {
            return a.y > b.y;
        }
        /*
        else
        {
            return a.x > b.y;
        }
        */
        return a.x > b.x;
    }
};

int main()
{
    //but, it's still just integers
    //we need a pq of objects
    //once we create object, we need to say which member of object we're comparing
    patient p1(5, 6, "LOL");
    patient p2(51, 4, "Za");
    patient p3(15, 10, "zs");
    patient p4(51, 11, "ha");
    patient p5(16, 12, "al");
    patient p6(52, 13, "sit");
    //cout<<p4.x<<endl;
    
    priority_queue<patient,vector<patient>, compare > pq4;
 
    pq4.push(p1);
    pq4.push(p2);
    pq4.push(p3);
    pq4.push(p4);
    pq4.push(p5);
    pq4.push(p6);

    patient pTemp = pq4.p2;
    cout << pTemp.x;

    /*
    while ( !pq4.empty() )
    {
        //patient pTemp = pq4.top();
        cout << pTemp.x << " " << pTemp.y << " " << pTemp.name<<endl;
        //pq4.pop();
    }
    */



    return 0;

}
#include <iostream>
using namespace std;
class PriorityQueue
{
private:
    
    int size;
    int arr[10];
    int end,begin;
public:
    PriorityQueue():size(0)
    {}
    void Push(int x)
    {
        
        if (size==0){
            arr[0]=x;
            size++;
        }
        else
        {
            int temp[size];
            int k=0;
            for (int i=0;i<size;++i)
            {
                temp[i]=arr[i];
                k=i;
            }
            temp[k+1]=x;
            int buff;
            for (int i=0;i<size;i++)
            {
                for (int j=size;j>i;j--)
                {
                    if (temp[j]>temp[j-1])
                    {
                        buff = temp[j-1];
                        temp[j - 1] = temp[j];
                        temp[j] = buff;
                    }
                }
            }
            
            for (int i=0;i<size+1;++i)
            {
                arr[i]=temp[i];
            }
            
            
            size++;
        }
    }
    void Show()
    {
        for (int i=0;i<size;++i)
        {
            cout<<arr[i]<<" ";
        }
    }
    void End()
    {
        int max=-1;
        for (int i=0;i<size;++i)
        {
            if (max<i)
            {
                end=arr[i];
            }
        }
        cout<<end;
        if (size==0)
        {
            cout<<"Первого элемента нет ! ";
        }
    }
    void Begin()
    {
        
        begin=arr[0];
        cout<<begin;
    }
    void Pop()
    {
        if (size==0)
        {
            cout<<"Очередь пустая";
            return;
        }
        int temp[size-1];
        int k=0;
        for (int i=0;i<size-1;++i)
        {
            temp[k]=arr[i+1];
            k++;
        }
        size--;
        for (int i=0;i<size;++i)
        {
            arr[i]=temp[i];
        }
    }
    int ClearQueue()
    {
        // нужно доделать
        return 0;
    }
};


int main() {
    PriorityQueue Cqu;
    cout<<"Очередь-";
    Cqu.Push(10);
    Cqu.Push(51);
    Cqu.Push(32);
    Cqu.Push(103);
    Cqu.Push(66);
    Cqu.Push(33);
    Cqu.Push(15);
    Cqu.Push(2);
    Cqu.Show();
    cout<<endl;
    cout<<"Удаление-";
    Cqu.Pop();
    Cqu.Pop();
    Cqu.Pop();
    Cqu.Pop();
    Cqu.Pop();
    Cqu.Pop();
    Cqu.Pop();
    Cqu.Show();
    cout<<endl;
    //cout<<"Удаляем все элементы-";
    //cout<<ClearQueue();
    cout<<endl;
    cout<<"Начало-";
    Cqu.Begin();
    cout<<endl;
    cout<<"Конец-";
    Cqu.End();
    cout<<endl;

    return 0;
}
//1 3 7 6 6 6 6 4 3 2 1 peak = 7
// 1 3 6 2 1 0 peak = 6
#include<iostream>
using namespace std;
class peak
{
    public:
    int peak = -1;
    int find_peak(int *arr,int size)
    {
        int mid = size/2;
        if(arr[mid] > arr[mid + 1])
        {
            peak = arr[0];
            for(int i = 0; i<=mid;i++)
            {
                if(arr[i] > peak)
                {
                    peak = arr[i];
                }
            }
            return peak;
        }
        else if(arr[mid] < arr[mid + 1])
        {
            peak = arr[mid];
            for(int i = mid; i < size;i++)
            {
                if(arr[i] > peak)
                {
                    peak = arr[i];
                }
            }
            return peak;
        }
        else if(arr[mid] == arr[mid + 1])
        {
            int left_mid,right_mid;
            left_mid = mid;
            right_mid = mid;
            while(arr[left_mid] == arr[mid])
            {
                left_mid--;
            }
            while(arr[right_mid] == arr[mid])
            {
                right_mid++;
            }
            if(arr[left_mid] > arr[right_mid])
            {
                peak = arr[left_mid];
                for(int i = 0; i <= left_mid;i++)
                {
                    if(arr[i] > peak)
                    {
                        peak = arr[i];
                    }
                }
                return peak;
            }
            else if(arr[left_mid] < arr[right_mid])
            {
                peak = arr[right_mid];
                for(int i = right_mid; i < size;i++)
                {
                    if(arr[i] > peak)
                    {
                        peak = arr[i];
                    }
                }
                return peak;
            }
        }
        return peak;
    }

};
int main()
{
    int size;
    cout << "Enter the size: " << endl;
    cin >> size;
    int arr[size];
    cout << "Enter the elements: ";
    for(int i=0 ; i<size; i++)
    {
        cin >> arr[i];
    }
    peak obj;
    cout << "The peak elements is: " << endl;
    cout << obj.find_peak(arr,size) << endl;
    
}
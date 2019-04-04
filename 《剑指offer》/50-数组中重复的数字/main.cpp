class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    /**
    *��������Ҫ�����������������
    *���������鶼��0-n-1��Χ�ڣ�˵�����û���ظ��Ļ�����ͨ�����������ֺ������±�һ��
    *���Ա�����������±�һ�¼�����һλ�������һ���������±��������ֱȽ�
    *������˵���Ѿ�����һ���������ظ�
    *��������ǰ����ǽ���Ҳ������������ֻص������±�һ�µ�λ��
    */
    bool duplicate(int numbers[], int length, int* duplication) {
        if(numbers==nullptr||length<0)
            return false;
        
        for(int i = 0;i<length;)
        {
            if(numbers[i]==i)
                i++;
            else if(numbers[i]== numbers[numbers[i]])
            {
                *duplication = numbers[i];
                return true;
            }else{
                swap(numbers[i],numbers[numbers[i]]);
            }
        }
        return false;
        
    }
};
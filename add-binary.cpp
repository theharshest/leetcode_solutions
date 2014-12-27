class Solution {
public:
    string addBinary(string a, string b) {
        string res="";
        int lena=a.length();
        int lenb=b.length();
        
        if(lena>lenb)
            for(int i=0; i<lena-lenb; i++)
                b.insert(0, "0");
        else
            for(int i=0; i<lenb-lena; i++)
                a.insert(0, "0");
        
        bool carry=false;
            
        for(int i=int(a.length())-1; i>=0; i--)
        {
            if(a[i]=='1' && b[i]=='1')
            {
                if(carry)
                    res.insert(0, "1");
                else
                {
                    res.insert(0, "0");
                    carry=true;
                }
            }
            else if(a[i]=='1' || b[i]=='1')
            {
                if(carry)
                    res.insert(0, "0");
                else
                    res.insert(0, "1");
            }
            else
            {
                if(carry)
                    res.insert(0, "1");
                else
                    res.insert(0, "0");
                carry=false;
            }
        }
        
        if(carry)
            res.insert(0, "1");
        
        return res;
    }
};

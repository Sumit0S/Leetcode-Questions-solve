class Solution {
    public int lengthOfLongestSubstring(String s) 
    {
        HashSet<Character> temp = new HashSet<>();

        int len=0;
        int j=0;
        for(int i=0; i<s.length(); i++)
        {
       
            while(j<i && (temp.contains(s.charAt(i))))
            {
                temp.remove(s.charAt(j));
                j++;
            }
                
            
            temp.add(s.charAt(i));
            len=Math.max(len, i - j + 1);
            
        }

        return len;
    }
}
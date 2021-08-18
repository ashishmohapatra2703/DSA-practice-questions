/*Validate an IP address (IPv4). An address is valid if and only if 
it is in the form "X.X.X.X", where each X is a number from 0 to 255.

For example, "12.34.5.6", "0.23.25.0", and "255.255.255.255" are valid IP addresses, 
while "12.34.56.oops", "1.2.3.4.5", and "123.235.153.425" are invalid IP addresses.

Examples:
ip = '192.168.0.1'
output: true

ip = '0.0.0.0'
output: true

ip = '123.24.59.99'
output: true

ip = '192.168.123.456'
output: false */

class Solution {
public:
    int isValid(string s) 
    {
        int start = 0;
        int parts = 1;
        for(int i=0; i<s.size()+1; i++)
        {
            if(s[i] == '.' or i == s.size())
            {
                int lenSubPart = i-start;
                if(lenSubPart == 0 or lenSubPart >= 4)
                    return false;
                string subPart = s.substr(start , lenSubPart);
                start = i+1;
    
                if(stoi(subPart) >= 256) //converts string to long int
                    return false;
                if(subPart[0] == '0')
                {
                    if(subPart.size() != 1) // .0. ->valid but 
                        return false;        //.06. ->not valid
                }
                
                if(s[i] == '.') parts++;
                if(parts >= 5)
                    return false;
            }
    
            else if(s[i]<'0' or s[i]>'9')
                return false;
        }
        
        if(parts <= 3)
            return false; // 1.1.1 -> invalid
        return true;
    }
};

/*Solution: PARSING

For each address, we split it into chunks delimited by a period. A valid address must have 4 chunks.
Then, for each chunk, 
we will check whether it is the string representation of a number from 0 to 255.
We need to check that all the characters in the string are digits, 
and that there are no leading zeroes, 
and the string-to-int representation is in the range [0, 255].

function fitsOneByte(chunk):
    # Does this string chunk represent a number
    # from 0 to 255?

    # If it's empty string, return false.
    if chunk.length == 0:
        return false

    # If any character in the string isn't a
    # digit, return false.
    for i from 0 to chunk.length - 1:
        if chunk[i] < '0' OR chunk[i] > '9':
            return false

    # If the string has a leading zero and isn't
    # zero, return false.
    if chunk.length >= 2 AND chunk[0] == '0':
        return false

    # Return true if and only if parsing the
    # chunk as an integer is between 0 and 255.
    return 0 <= int(chunk) AND int(chunk) <= 255

function validate(address):
    # If the number of periods is not 3, then
    # it can't be an IP address.
    chunks = address.split('.')
    if chunks.length != 4:
        return false

    # Check that each chunk delimited by periods,
    # represents a number from 0-255.
    for chunk in chunks:
        if not fitsOneByte(chunk):
            return false

    return true

Note: If our library does not have the builtin “split” for strings, we could still write one as shown below.
We record seen characters into a buffer, and flush the buffer into our answer every time we see a delimiting character.

function split(string, delimiter):
    buffer = ""
    answer = []
    for character in string:
        if character == delimiter:
            answer.push(buffer)
            buffer = ""
        else:
            buffer += character

    answer.push(buffer)
    return answer

Computational Complexity
Say the given string is N characters. Our split operation takes O(N) time and O(N) space. 
Our fitsOneByte operation takes a linear amount of time and space for each chunk, 
and the sum of the chunks is the whole string.
Thus, the time complexity is O(N), and the space complexity is O(N).

Time Complexity: O(N), where N is the number of characters in ip. Our split operation takes O(N) time, and our fitsOneByte operation takes a linear amount of time for each chunk, and the sum of the chunks is the whole string.

Space Complexity: O(N), the space used when considering each part of the original string ip.*/
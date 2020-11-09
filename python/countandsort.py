# Program that counts the number of occurrences of each letter in a string


# Capitalizes and formats string to only include lettered ASCII characters
def formatString():
    prompt = input("Enter your message: ")
    message = [x.upper() for x in prompt if x.upper() >= 'A' and x.upper() <= 'Z']
    
    return message

# Count the letters
def countLetters(msg,letlist):
    size = len(msg)
    i = 0
    while i < size:
        scn = i+1
        count = 1
        # print(f"INDEX {i}\n========")
        while scn < size:
            if msg[i] == msg[scn]:
                # print(f"Matched with {msg[scn]} at index {scn}")
                count += 1
                msg.pop(scn)
                # print(msg)
                size -= 1
            else:
                scn += 1
        letlist.append((msg[i],count))
        i += 1

    # print(msg)
    
# Bubble sort
def bubbleSort(pairlist):
    switched = True
    while switched != False:
        swapped = False
        for let in range(0,len(pairlist)-1):
            if pairlist[let][1] < pairlist[let+1][1]:
                swapped = True
                tmp = pairlist[let+1] 
                pairlist[let+1] = pairlist[let]
                pairlist[let] = tmp
        
        if swapped != True:
            switched = False


# Main function
letters = []
message = formatString()
# print(message)
countLetters(message,letters)

bubbleSort(letters)

for x in letters:
    print(x)






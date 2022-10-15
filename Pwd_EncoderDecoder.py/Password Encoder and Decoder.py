from base64 import b64encode
from base64 import b64decode
from pyfiglet import figlet_format as style

#__main__
while(1):    
    print("Press :-",
      '\n\t1 to encode a password',
      '\n\t2 to decode a password',
      '\nt any other to exit')
    ch = int(input("Enter your choice = "))
    
    if(ch==1):
        pasd = input('Enter your password = ')
        
        pasd = pasd.encode()
        #converting string format -> byte format

        pasd = b64encode(pasd)
        #converting byte format -> ascii format

        pasd = pasd.decode()
        #converting ascii format -> string format

        print("Your password is successfully encoded... ", "\U0001F973")
        print("Encoded password = ", pasd)

    elif(ch==2):
        pasd = input("Enter your encoded password = ")

        pasd = pasd.encode()
        #converting the string format -> byte format

        result = b64decode(pasd)
        #converting ascii password of user -> byte format

        result = result.decode()
        #converting byte format -> string format

        print("Your decoded password is = ", result)

    else:
        print()
        print(style("Come Back Again Chief ", font="digital") )
        break

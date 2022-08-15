##needs some work but the gist is there

height=int(input("Enter height from 1 to 8 "))
 
if height<1 or height>8:
 raise Exception("Invalid input ")

for row in range(height):
    space=height-row-1
    while space>0:
            space-=1
            print(" ")
            for hash in range (row+1):
                print("#")
    print("\n")            











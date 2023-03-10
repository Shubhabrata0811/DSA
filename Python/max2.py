arr=[]
n=int(input("Enter the number of elements:"))
arr.append(int(input("Enter the number:")))
max=arr[0]
for i in range(1,n):
    arr.append(int(input("Enter the number:")))
    if(max<arr[i]):
        max=arr[i]
print("The maximum number is:",max)
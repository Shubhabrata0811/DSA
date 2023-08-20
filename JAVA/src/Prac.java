import java.io.*;
import java.nio.file.*;
import java.util.*;
public class Prac {
    public static void main (String[] args) throws FileNotFoundException, IOException, NoSuchFileException{
        // Scanner sc = new Scanner(System.in);

        // Path lowerPathe = Paths.get("JAVA/src/lower.txt");
        // if(!Files.exists(lowerPathe)){
        //     Files.createFile(lowerPathe);
        // }
        // String lowerText = Files.readString(lowerPathe);
        
        // if(!Files.exists(upperPathe)){
        //     Files.createFile(upperPathe);
        // }
        Path upperPathe = Paths.get("JAVA/src/upper.txt");
        //Files.writeString(upperPathe,upperText,java.nio.file.StandardOpenOption.APPEND);
        String uppercon = Files.readString(upperPathe);
        Path newp = Paths.get("JAVA/src/moveup.txt");
        Files.move(upperPathe,newp);
        Files.delete(upperPathe);
        //sc.close();
    
    }

}
/*



import java.io.*;
import java.nio.file.*;
import java.util.Scanner;

class t1 extends Thread{
    public void run(){
        for(int i=0;i<50;i++){
            System.out.println("In t1 type :"+i);
            try{
                if(i==6){
                    t1.sleep(400L);
                }
            }catch(InterruptedException ie){
                System.out.println(ie);
            }
        }
    }
}

class t2 implements Runnable{
    public void run(){
        for(int i=100;i<150;i++){
            System.out.println("In t2 type :"+i);
        }
    }
}

public class Prac{
	public static void main (String[] args) throws InterruptedException{
		t1 eg1 = new t1();
        t2 eg2 = new t2();
        Thread t = new Thread(eg2);

        eg1.start();
        t.start();

    }
}

import java.util.Scanner;

class finallyUse{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int i=0;
        int[] arr = new int[5];
        try{
            System.out.print("\nEnter numbers");
            while(true){
                arr[i]=sc.nextInt();
                i++;
            }
        }catch(ArrayIndexOutOfBoundsException aioobie){
            System.out.println("Array index out of bounds:"+aioobie);
        }finally{
            System.out.println(i);
            sc.close();
        }
        System.out.println("Out side the try");
    }
}*/
public class stlength {
    static public void main(String args[]){
        String s = "Bob the bulider";
        int count = 0;
        try{
            while(true){
                char c = s.charAt(count);
                count++;
            }
            
        }catch(Exception ex){
            System.out.println("Length = "+count);
        }

    }
}

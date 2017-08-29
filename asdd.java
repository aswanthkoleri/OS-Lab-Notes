/* IMPORTANT: Multiple classes and nested static classes are supported */


 
//imports for BufferedReader
import java.io.BufferedReader;
import java.io.InputStreamReader;

//import for Scanner and other utility  classes
import java.util.*;

// Assignment0 class
class Assignment0{
        private String id;
        private  int type ;
        private int marks;
        private String checker;
        private String notes;
    Assignment0(String id,int type,String checker,String notes,int marks)
    {
        this.id = id;
        this.type=type;
        this.checker = checker;
        this.notes = notes;
        this.marks = marks;
    }
    public int getTotalmarks(){
        return marks;
    }  
    public void printAssignment(){
        System.out.println(id+" "+marks);
    }
}
class Assignment1{
        private String id;
        private  int type ;
        private int correct;
        private int wrong;
    Assignment1(String id,int type,int correct,int wrong)
    {
        this.id = id;
        this.type=type;
        this.correct = correct;
        this.wrong = wrong;
    }
    
    public int getTotalmarks(){
        return ((correct*4) - wrong);
    }
    public void printAssignment(){
        System.out.println(id+" "+((correct*4)-wrong));
    }

}
class Assignment2{
        private String id;
        private  int type;
        private int penalty;
        private String lang;
        private int totalTime;
        private int marks;
    Assignment2(String id,int type,int totalTime,int penalty,String lang,int marks)
    {
        this.id = id;
        this.type=type;
        this.penalty = penalty;
        this.totalTime = totalTime;
        this.lang = lang;
        this.marks = marks;
    }
       
        public int getTotalmarks(){
        return (marks-penalty);
        }  
        public void printAssignment(){
        System.out.println(id+" "+(marks-penalty));
    }
    }

class Student{
    Scanner s = new Scanner(System.in).useDelimiter("\\s");
    // Rollno Name Intelligence
    private String rollNo;
    private String name;
    private int j;
    private int k;
    private int l;
    Assignment0 ass0[] = new Assignment0[no];
    Assignment1 ass1[] = new Assignment1[no];
    Assignment2 ass2[] = new Assignment2[no];
    Student(String rollNo,String name){
        this.rollNo = rollNo ;
        this.name = name ;
        this.i=0;
        this.j=0;
        this.k=0;
    }
    public String getrollNo(){
        return rollNo;
    }
    public String getname(){
        return name;
    }
    public void printStudent(){
        System.out.println(rollNo+" "+name);
    }
    public void typeAssignments(){
            int no = s.nextInt();
            
            for(int i=0;i<no;i++)
            {
                String id= s.next();
                int type = s.nextInt();
                if(type==0)
                {
                    ass0[j]=new Assignment0(id,type,s.next(),s.next(),s.nextInt());
                    j++;
                }
                if(type==1)
                {
                    ass1[k] = new Assignment1(id,type,s.nextInt(),s.nextInt());
                    k++;
                }
                if(type==2)
                {
                   ass2[l] = new Assignment2(id,type,s.nextInt(),s.nextInt(),s.next(),s.nextInt());
                    l++;
                } } }
    public void print(){
        int sum =0;
             for(int i=0;i<j;i++){
                   ass0[i].printAssignment();
                   sum = sum + ass0[i].getTotalmarks();
             }
             System.out.println(sum);
             sum=0;
              for(int i=0;i<k;i++){
                   ass1[i].printAssignment();
                   sum = sum + ass1[i].getTotalmarks();
                
            }
            System.out.println(sum);
             sum=0;
             for(int i=0;i<l;i++){
                
                    ass2[i].printAssignment();
                    sum = sum + ass2[i].getTotalmarks();
            }
            System.out.println(sum);
        }   }

public class Question4 {
    public static void main(String args[] ) throws Exception {
        Scanner s = new Scanner(System.in).useDelimiter("\\s");
        int N = s.nextInt();
        while(N-- != 0){
            Student stu = new Student(s.next(),s.next()); 
            stu.typeAssignments();
            stu.printAssignment();       

        }
    }
}

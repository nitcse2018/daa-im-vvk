import java.io.*;
public class CharStream
{ 
    public static void main(String[] args) throws IOException 
    { 
        FileReader fr = null; 
        FileWriter fw = null;
        try 
        { 
            fr = new FileReader("input.txt"); 
            fw = new FileWriter("output_char.txt");
            int temp; 
            while ((temp = fr.read()) != -1) 
                 fw.write((char)temp); 
        } 
        finally 
        {   
            if (fr != null)             
                fr.close();
            if (fw != null)             
                fw.close();
        } 
    } 
} 
import java.io.*;
import java.net.*;
import java.util.regex.*;
import java.io.File;
//  import java.nio.*;
public class fileshortcut
{
	public static void main(String[] args) throws IOException
	{	
	
	String mname;	
	File folder=new File("./movies");		//path of folder consisting files
	File[] allfiles=folder.listFiles();		//putting all files on above path into an array
	for(File f:allfiles)					//for evry file
	{	
		mname=f.getName();
		String pat2="([^\\.]*).*";			//pattern of file name required
		Pattern r2=Pattern.compile(pat2);
		Matcher m2=r2.matcher(mname);
		if(m2.find())
		{
			System.out.println(f.getName());
			String link="http://www.rottentomatoes.com/m/"+m2.group(1).replaceAll(" ","_");		//link to open and read genre
			URL rotten=new URL(link);
			InputStreamReader obj=new InputStreamReader(rotten.openStream());		

//to read content of webpage 
			BufferedReader in= new BufferedReader(obj);
			String line;
			String pat=".genre.>(\\w+)<";		//pattern to be matched from html of that page <span itemprop="genre">comedy</span>
			while((line=in.readLine())!=null)		//will read html of the page
			{	
				Pattern r=Pattern.compile(pat);		
				Matcher m=r.matcher(line);
				if(m.find())
				{
					System.out.println(m.group(1));		//if patten match genre in printed
				}
				try
				{
					File o=new File("./movies/"+m.group(1));	//directory of that genre is created
					o.mkdir();
				}
				catch(Exception e)
				{
				}
				
				/*try
				{
					Path orig="./movies/"+f.getName();		//path whose shortcut has to be created
					Path target="./movies/"+m.group(1);		//path where shrtcut has to be created
					Files.createSymbolicLink(target,orig);		//shortcut is creted
				}
				catch(IOException x)
				{
					System.out.println(x);
				}
				catch(UnsupportedOperationException x)
				{	//Some files systems do not support Symbolic link
					System.out.println(x);
				}*/
			}
		}
	}
	}
}
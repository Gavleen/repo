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
	File folder=new File("./movies");
	File[] allfiles=folder.listFiles();
	for(File f:allfiles)
	{	
		mname=f.getName();
		String pat2="([^\\.]*).*";
		Pattern r2=Pattern.compile(pat2);
		Matcher m2=r2.matcher(mname);
		if(m2.find())
		{
			System.out.println(f.getName());
			String link="http://www.rottentomatoes.com/m/"+m2.group(1).replaceAll(" ","_");
			URL rotten=new URL(link);
			InputStreamReader obj=new InputStreamReader(rotten.openStream());		//to read content of webpage 
			BufferedReader in= new BufferedReader(obj);
			String line;
			String pat=".genre.>(\\w+)<";		//<span itemprop="genre">comedy</span>
			while((line=in.readLine())!=null)
			{	
				Pattern r=Pattern.compile(pat);
				Matcher m=r.matcher(line);
				if(m.find())
				{
					System.out.println(m.group(1));
				}
				try
				{
					File o=new File("./movies/"+m.group(1));
					o.mkdir();
				}
				catch(Exception e)
				{
				}
				
				/*try
				{
					Path orig="./movies/"+f.getName();
					Path target="./movies/"+m.group(1);
					Files.createSymbolicLink(target,orig);
				}
				catch(IOException e)
				{}*/
			}
		}
	}
	}
}
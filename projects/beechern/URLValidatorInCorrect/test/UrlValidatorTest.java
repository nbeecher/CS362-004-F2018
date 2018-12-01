package test;



import incorrect.UrlValidator;
import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!





public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   
   public void testManualTest()
   {
	   String testing = "";
	   
	   //Test ALLOW ALL SCHEMES	  
	  UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   	 	    
	   System.out.println("Manual tests for ALLOW ALL SCHEMES");		   
	   System.out.println(String.format("%s", testing = "http://www.amazon.com/") + "\tExpect: true\tActual: " + urlVal.isValid(testing));
	   System.out.println(String.format("%s", testing = "http://www.google.com") + "\tExpect: true\tActual: " + urlVal.isValid(testing));
	   System.out.println(String.format("%s", testing = "http://google.com/") + "\tExpect: true\tActual: " + urlVal.isValid(testing));
	   System.out.println(String.format("%s", testing = "http://192.160.1") + "\tExpect: true\tActual: " + urlVal.isValid(testing));	   
	   
	   System.out.println(String.format("%s", testing = "http://300.160.33.257") + "\tExpect: false\tActual: " + urlVal.isValid(testing)); //ip address out of range
	   System.out.println(String.format("%s", testing = "www.google.com") + "\t\tExpect: false\tActual: " + urlVal.isValid(testing));	   
	   System.out.println(String.format("%s", testing = "http/1.2.3:-1/..//../") + "\tExpect: false\tActual: " + urlVal.isValid(testing));
	   System.out.println(String.format("%s", testing = "http:// www.amazon.com") + "\tExpect: false\tActual: " + urlVal.isValid(testing));
	   System.out.println(String.format("%s", testing = "http://www") + "\tExpect: false\tActual: " + urlVal.isValid(testing));
	   System.out.println(String.format("%s", testing = "http:") + "\tExpect: false\tActual: " + urlVal.isValid(testing));
	   System.out.println(String.format("%s", testing = "http:/www.amazon.com") + "\tExpect: false\tActual: " + urlVal.isValid(testing));
	   System.out.println(String.format("%s", testing = " ") + "\t\t\tExpect: false\tActual: " + urlVal.isValid(testing));
	   
	   //cause fatal errors
	   //System.out.println(String.format("%s", testing = "https://google.com/") + "\tExpect: true\tActual: " + urlVal.isValid(testing));
	   //System.out.println(String.format("%s", testing = "ftp://google.com/") + "\tExpect: true\tActual: " + urlVal.isValid(testing));	   
	   
	   //Test default
	   UrlValidator urlValD = new UrlValidator(0);
	   
	   System.out.println(" ");  
	   System.out.println("Manual tests for default scheme");	  
	   
	   System.out.println(String.format("%s", testing = "http://www.amazon.com/") + "\tExpect: true\tActual: " + urlValD.isValid(testing));
	   System.out.println(String.format("%s", testing = "http://www.google.com") + "\tExpect: true\tActual: " + urlValD.isValid(testing));
	   System.out.println(String.format("%s", testing = "http://google.com/") + "\tExpect: true\tActual: " + urlValD.isValid(testing));
	   System.out.println(String.format("%s", testing = "http://192.160.1") + "\tExpect: true\tActual: " + urlValD.isValid(testing));	   
	   
	   System.out.println(String.format("%s", testing = "http://300.160.33.257") + "\tExpect: false\tActual: " + urlValD.isValid(testing)); //ip address out of range
	   System.out.println(String.format("%s", testing = "www.google.com") + "\t\tExpect: false\tActual: " + urlValD.isValid(testing));	   
	   System.out.println(String.format("%s", testing = "http/1.2.3:-1/..//../") + "\tExpect: false\tActual: " + urlValD.isValid(testing));
	   System.out.println(String.format("%s", testing = "http:// www.amazon.com") + "\tExpect: false\tActual: " + urlValD.isValid(testing));
	   System.out.println(String.format("%s", testing = "http:/www.amazon.com") + "\tExpect: false\tActual: " + urlValD.isValid(testing));
	   System.out.println(String.format("%s", testing = " ") + "\t\t\tExpect: false\tActual: " + urlValD.isValid(testing));
	   System.out.println(String.format("%s", testing = "https://www.amazon.com/") + "\tExpect: true\tActual: " + urlValD.isValid(testing));
	   System.out.println(String.format("%s", testing = "ftp://www.amazon.com/") + "\tExpect: true\tActual: " + urlValD.isValid(testing));	   

		System.out.println("");
   }
   
   
   public void testYourFirstPartition()
   {
	 // Scheme Partition
	 System.out.println("");
	 System.out.println("First partition: schemes ");
	 
	 String[] testSchemes = {"http", "https", "ftp", " "};
	 
	 UrlValidator test = new UrlValidator(testSchemes, UrlValidator.ALLOW_ALL_SCHEMES);
	 UrlValidator test2 = new UrlValidator(testSchemes, 0);
	 
	 for(int i=0; i < testSchemes.length; i++)
	 {
	 	String cur = testSchemes[i];
	 	
	 	System.out.println(cur + ":");
	 	System.out.println(String.format("%s",  "ALLOW ALL SCHEMES") + "\t" + test.isValidScheme(cur));
	 	System.out.println(String.format("%s",  "DEFAULT") + "\t\t\t" + test2.isValidScheme(cur));
	 	System.out.println("");
	 }
	 
	 
	  

   }
   
   public void testYourSecondPartition(){
		 // Query Partition 
		 System.out.println("");
		 System.out.println("Second partition: Query ");
		 
		 String[] testSchemes = {"?&crsource=google", "?&&&&crsource=google", "crsource=google", " ", "http", "", "?"};
		 
		 UrlValidator test = new UrlValidator(testSchemes, UrlValidator.ALLOW_ALL_SCHEMES);
		 UrlValidator test2 = new UrlValidator(testSchemes, 0);
		 
		 for(int i=0; i < testSchemes.length; i++)
		 {
		 	String cur = testSchemes[i];
		 	
		 	System.out.println(cur + ":");
		 	System.out.println(String.format("%s",  "ALLOW ALL SCHEMES") + "\t" + test.isValidQuery(cur));
		 	System.out.println(String.format("%s",  "DEFAULT") + "\t\t\t" + test2.isValidQuery(cur));
		 	System.out.println("");
		 }		 

		 
   }   
   
  
   
   public void testIsValid()
   {
       UrlValidator val = new UrlValidator(null, null, 0);
       //You can use this function for programming based testing
       String[] goodURLs = {"http://google.com", "oregonstate.edu", "http://www.yahoo.com/", "https://hackaday.com/index"};
       String[] badURLs = {"as;dlkfjas;ldkfj", "oregonstate.oregonstate.http//e", "moc.elgoog.www//:ptth", "http://notgood"};
       
       for (int x=0; x<goodURLs.length; x++) {
          try {    
                 if (val.isValid(goodURLs[x])) {
                  System.out.println("good url is valid, nice.");
              } else {
                  System.out.println("good url is invalid, uh oh.");
              }
          } catch(Error e) {
              System.out.println("That URL caused the program to crash.");
          }
       }
       for (int x=0; x<badURLs.length; x++) {
          try {
              if (val.isValid(badURLs[x])) {
                  System.out.println("bad url is valid, uh oh.");
              } else {
                  System.out.println("bad url is invalid, nice.");
              }
          } catch(Error e) {
              System.out.println("That URL caused the program to crash.");
          }
       }
   }
   


}

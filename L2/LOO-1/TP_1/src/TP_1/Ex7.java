package TP_1;

public class Ex7
{
    public static void main(String[] args)
    {
        try {
            if (args.length != 3)
            {
                throw new Exception("The number of parameter is bad. Please use three parameter");
            }
        } catch (Exception exception){
            System.err.println("Error: " + exception.getMessage());
        }

    }
}

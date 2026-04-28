public class Vartypes{

    int instancevar1=23;
    static short staticvar2;
    final double f_finalvar= 33.56;
    float fvar2=34.56f;
    public void dispvars()
    {
        double dvar_local=33.456;
        System.out.println("\n Instance var : " + instancevar1);
        System.out.println("\n staticvar2 var : " + staticvar2);
        System.out.println("\n dvar_local : " + dvar_local);
          System.out.println("\n f_finalvar : " + f_finalvar);
            System.out.println("\n fvar2 : " + fvar2);
    }

    public static void main()
    {
        Vartypes obj1 = new Vartypes();
        obj1.dispvars();
    }
}
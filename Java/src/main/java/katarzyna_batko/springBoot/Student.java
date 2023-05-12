package katarzyna_batko.springBoot;

public class Student implements Comparable<Student>{

    int id;
    String imie;
    String nazwisko;
    //String imieOjca;
   // String imieMamy;
    int nrTel;
    int rokUrodzenia;
    double iloscPunktow;
    StudentCondition stanStudenta;

    Student(int id, String imie, String nazwisko, int rokUrodzenia, double iloscPunktow, StudentCondition stanStudenta, int nrTel){
        this.id = id;
        this.imie = imie;
        this.nazwisko = nazwisko;
        this.rokUrodzenia = rokUrodzenia;
        this.iloscPunktow = iloscPunktow;
        this.stanStudenta = stanStudenta;
       // this.imieMamy = imieMamy;
       // this.imieOjca = imieOjca;
        this.nrTel = nrTel;
    }

    public int getId() {
        return id;
    }
    public String getImie() {
        return imie;}
      public String getNazwisko() {
        return nazwisko;
    }
    public int getRokUrodzenia() {
        return rokUrodzenia;
    }
   /*// public String getImieMamy(){
      //  return imieMamy;
    }
   // public String getImieOjca(){
        //return imieOjca;
    }*/
    public int getNrTel(){return nrTel;}

    public double getIloscPunktow(){
        return iloscPunktow;
    }

    public String setImie(String text) {
        return imie;}
    public String setNazwisko(String text) {
        return nazwisko;
    }
    public int setRokUrodzenia(int rokUrodzeniaInt) {
        return rokUrodzenia;
    }
    /*public String setImieMamy(){
        return imieMamy;
    }
    public String setImieOjca(){
        return imieOjca;
    }*/

    public int setNrTel(int i){
        return nrTel;
    }
    public double setIloscPunktow(double punkty){
        return iloscPunktow;
    }




    public void print()
    {
        System.out.println("Dane: " + imie + ' ' + nazwisko + ' ' + rokUrodzenia + ' ' + iloscPunktow + ' ' + stanStudenta);
    }


    @Override
    public boolean compareTo(Student other) {
        if(this.nazwisko == other.nazwisko) return true;
        else return false;
    }

    public StudentCondition getCondition() {
        return stanStudenta;
    }

    public String toCsvString() {
        return String.format("%s,%s,%s", imie, nazwisko, rokUrodzenia);
    }
}


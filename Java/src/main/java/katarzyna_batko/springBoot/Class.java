package katarzyna_batko.springBoot;

import java.util.*;

public class Class {
    private String groupName;
    private List<Student> studentList;
    private int maxStudents;
    private int number = 1;
    private int idClass;
    public Class(String groupName, int maxStudents) {
        this.groupName = groupName;
        this.maxStudents = maxStudents;
        this.studentList = new ArrayList<>();
        this.idClass = idClass;
    }

    public int getIdClass() { return idClass;}
    public String getGroupName() {
        return groupName;
    }

    public List<Student> getStudentList() {
        return studentList;
    }

    public int getMaxStudents() {
        return maxStudents;
    }
    public void addStudent(Student student) {
        if(studentList.contains(student)) {
         System.out.println("Studenci zostali dodani");
            return;
        }
        if(studentList.size() >= maxStudents){
            System.err.println("Zostala przekroczona maksymalna ilosc studentow");
            return;
        }
        studentList.add(student);
    }
    public void addPoints(Student student, double iloscPunktow) {
        student.iloscPunktow += iloscPunktow;
        System.out.println("Student: "+ student.imie + " ma ilosc punktow " + student.iloscPunktow);
    }
    public void getStudent(Student student){
        if(student.iloscPunktow <= 0.0){
            studentList.remove(student);
        }
        System.out.println("Student: "+ student.imie + " zostal usuniety");
    }
    public void removeStudent(Student student) {
        studentList.remove(student);
    }
    public Student getStudentById(int id) {
        for (Student student : studentList) {
            if (student.getId() == id) {
                return student;
            }
        }
        return null;
    }
    public void changeCondition(Student student, StudentCondition newCondition) {
        student.stanStudenta = newCondition;
        System.out.println("Student: "+ student.imie + " status zostal zmieniony " + student.stanStudenta);
    }
    public void removePoints(Student student, double iloscPunktów){
        student.iloscPunktow -= iloscPunktów;
        System.out.println("Student: "+ student.imie + " has a " + student.iloscPunktow);
    }
    public Student search(String lastName){
        for(Student student : studentList){
            if(student.getNazwisko().equals(student.nazwisko)) {
                System.out.println("Student: "+ student.nazwisko + " zostal znaleziony");
                String name = student.nazwisko;
                return student;
            }
        }
        return null;
    }
    public List<String> searchPartial(String name){
        List<String> matchingStudents = new ArrayList<>();
        String x = "";
        for(Student student : studentList){
            if(student.nazwisko.toLowerCase().contains(name.toLowerCase())){
                x = student.nazwisko;
                matchingStudents.add(String.valueOf(student));
            }
        }
        System.out.println("Szukanie studenta po nazwisku " + x);
        return matchingStudents;
    }
    public int countByCondition(StudentCondition condition){
        int count = 0;
        for(Student student  : studentList){
            if(student.getCondition() == condition){
                count++;
            }
        }
        System.out.println("Punkty studenta to: " + count);
        return count;
    }
    public void summary(){
        for(Student student : studentList){
            System.out.println(student.nazwisko.toString());
        }
    }

    public void sortByName(){
        Collections.sort(studentList, new Comparator<Student>() {
            @Override
            public int compare(Student o1, Student o2) {
                return o1.nazwisko.compareTo(o2.nazwisko);
            }
        });
    }
    public void sortByPoints(){
        Collections.sort(studentList, new pointComparator());
    }

    private class pointComparator implements Comparator<Student>{
        @Override
        public int compare(Student o1, Student o2){
            if(o1.iloscPunktow > o2.iloscPunktow) return 1;
            else return 0;
        }
    }
    void max()
    {
        System.out.println((Collections.max(studentList, new pointComparator())).nazwisko);
    }
    public int getPercentageFull() {

        return studentList.size() / number * 100;
    }

}


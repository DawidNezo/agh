package katarzyna_batko.springBoot;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import java.nio.charset.StandardCharsets;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

@RestController
@RequestMapping("/api")
public class Controller {
    ClassContainer container = new ClassContainer();

    // Endpoint 1: Dodawanie studenta
    @PostMapping("/student")
    public ResponseEntity<String> addStudent(@RequestParam String className, @RequestBody Student student) {
        Class foundClass = container.getClass(className);

        if(foundClass == null) {
            return ResponseEntity.ok("Nie ma klasy: " + className);
        }

        foundClass.addStudent(student);

        return ResponseEntity.ok(student.toString());
    }

    // Endpoint 2: Usuwanie studenta
    @DeleteMapping("/student/{id}")
    public Object deleteStudent(@PathVariable int id) {
        Student student = container.getStudent(id);

        if (student == null) {
            return ResponseEntity.ok("Nie ma studenta o ID: " + id);
        }

        container.removeStudent(student);
        return ResponseEntity.ok("Usunięto studenta o ID: " + id);
    }

    // Endpoint 3: Zwracanie średniej oceny lub wszystkich ocen z przedmiotu dla studenta
    @GetMapping("/student/{id}/grade")
    public ResponseEntity<String> getGrade(@PathVariable int id) {
        Student student = container.getStudent(id);

        if (student == null) {
            return ResponseEntity.ok("Nie ma studenta o ID " + id);
        }

        return ResponseEntity.ok("Ilosc punktow studenta o ID: " + id + " wynosi: " + student.getIloscPunktow());
    }

    // Endpoint 4: Zwracanie wszystkich studentów w formie pliku CSV
    @GetMapping(value = "/student/csv", produces = "text/csv")
    public ResponseEntity<byte[]> getStudentsCSV() {
        List<Student> students = container.getAllStudents(); // Pobierz listę wszystkich studentów

        // Tworzenie zawartości pliku CSV
        String csvContent = students.stream()
                .map(Student::toCsvString)
                .collect(Collectors.joining("\n"));

        // Konwertowanie zawartości na tablicę bajtów
        byte[] csvBytes = csvContent.getBytes(StandardCharsets.UTF_8);

        // Ustawienie nagłówków odpowiedzi
        HttpHeaders headers = new HttpHeaders();
        headers.setContentType(MediaType.parseMediaType("text/csv"));
        headers.setContentLength(csvBytes.length);
        headers.setContentDispositionFormData("attachment", "students.csv");

        // Zwrócenie odpowiedzi HTTP z zawartością pliku CSV
        return new ResponseEntity<>(csvBytes, headers, HttpStatus.OK);
    }

    // Endpoint 5: Zwracanie wszystkich przedmiotów/grup
    @GetMapping("/course")
    public ResponseEntity<Map<String, String>> getCourses() {
        return ResponseEntity.ok(container.getClasses());
    }


    // Endpoint 6: Dodawanie nowego przedmiotu/grupy
    @PostMapping("/course")
    public ResponseEntity<String> addCourse(@RequestBody String className) {
        container.addClass(className, 10);

        return ResponseEntity.ok("Dodano klase");
    }

    // Endpoint 7: Usuwanie przedmiotu/grupy
    @DeleteMapping("/course/{id}")
    public ResponseEntity<String> deleteCourse(@PathVariable String id) {
        container.removeClass(id);

        return ResponseEntity.ok("Usunięto przedmiot/grupę o ID: " + id);
    }

    // Endpoint 8: Zwracanie wszystkich studentów w grupie
    @GetMapping("/course/{id}/students")
    public ResponseEntity<List<Student>> getCourseStudents(@PathVariable String id) {
        Class foundClass = container.getClass(id);

        if(foundClass != null) {
            return ResponseEntity.ok(foundClass.getStudentList());
        }

        return null;
    }

    // Endpoint 9: Zwracanie zapełnienia procentowego grupy
    @GetMapping("/course/{id}/fill")
    public ResponseEntity<String> getCourseFill(@PathVariable String id) {
        Class foundClass = container.getClass(id);

        if(foundClass != null) {
            return ResponseEntity.ok("Zapełnienie grupy o ID " + id + " " + foundClass.getPercentageFull());
        }

        return null;
    }

    // Endpoint 10: Dodawanie oceny dla przedmiotu/grupy
    @PostMapping("/rating")
    public ResponseEntity<String> addRating() {
        // Logika dodawania oceny dla przedmiotu/grupy
        return ResponseEntity.ok("Dodano ocenę dla przedmiotu/grupy");
    }
}



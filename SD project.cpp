#include <bits/stdc++.h>
using namespace std;

// Class Definitions
class Hospital {
public:
    string H_name;
    string location;
    int available_beds;
    float rating;
    string contact;
    string doctor_name;
    int price;
};

class Patient : public Hospital {
public:
    string P_name;
    int P_id;
    string contact;
};

class Doctor {
public:
    string name;
    string specialization;
    string contact;
    float experience;
};

class Appointment {
public:
    int appointment_id;
    string patient_name;
    string doctor_name;
    string date_time;
};

class Bill {
public:
    int bill_id;
    int patient_id;
    int amount;
    string date;
};

class Prescription {
public:
    int prescription_id;
    string patient_name;
    string doctor_name;
    vector<string> medications;
};

class Department {
public:
    string name;
    string head;
    int staff_count;
};

class Staff {
public:
    string name;
    string role;
    string contact;
    float experience;
};

class MedicalEquipment {
public:
    string equipment_name;
    int quantity;
    string status; // e.g., "Available", "Under Maintenance"
};

class EmergencyContact {
public:
    string patient_name;
    string contact_name;
    string relationship;
    string contact_number;
};

class PatientHistory {
public:
    int patient_id;
    vector<string> medical_conditions;
    vector<string> treatments;
};

// Print Functions
void PrintHospitalData(const vector<Hospital>& hospitals) {
    cout << left << setw(20) << "HospitalName"
         << setw(20) << "Location"
         << setw(20) << "Beds_Available"
         << setw(10) << "Rating"
         << setw(20) << "Hospital_Contact"
         << setw(20) << "Doctor_Name"
         << setw(15) << "Price_Per_Bed" << endl;

    for (const auto& h : hospitals) {
        cout << setw(20) << h.H_name
             << setw(20) << h.location
             << setw(20) << h.available_beds
             << setw(10) << h.rating
             << setw(20) << h.contact
             << setw(20) << h.doctor_name
             << setw(15) << h.price << endl;
    }
    cout << endl;
}

void PrintPatientData(const vector<Patient>& patients) {
    cout << left << setw(20) << "Patient_Name"
         << setw(15) << "Patient_Id"
         << "Patient_Contact" << endl;

    for (const auto& p : patients) {
        cout << setw(20) << p.P_name
             << setw(15) << p.P_id
             << p.contact << endl;
    }
    cout << endl;
}

void PrintDoctorData(const vector<Doctor>& doctors) {
    cout << left << setw(20) << "Doctor_Name"
         << setw(20) << "Specialization"
         << setw(20) << "Contact"
         << "Experience (Years)" << endl;

    for (const auto& d : doctors) {
        cout << setw(20) << d.name
             << setw(20) << d.specialization
             << setw(20) << d.contact
             << d.experience << endl;
    }
    cout << endl;
}

void PrintAppointmentData(const vector<Appointment>& appointments) {
    cout << left << setw(20) << "Appointment_ID"
         << setw(20) << "Patient_Name"
         << setw(20) << "Doctor_Name"
         << "Date_Time" << endl;

    for (const auto& a : appointments) {
        cout << setw(20) << a.appointment_id
             << setw(20) << a.patient_name
             << setw(20) << a.doctor_name
             << a.date_time << endl;
    }
    cout << endl;
}

void PrintBillData(const vector<Bill>& bills) {
    cout << left << setw(20) << "Bill_ID"
         << setw(20) << "Patient_Id"
         << setw(20) << "Amount"
         << "Date" << endl;

    for (const auto& b : bills) {
        cout << setw(20) << b.bill_id
             << setw(20) << b.patient_id
             << setw(20) << b.amount
             << b.date << endl;
    }
    cout << endl;
}

void PrintPrescriptionData(const vector<Prescription>& prescriptions) {
    cout << left << setw(20) << "Prescription_ID"
         << setw(20) << "Patient_Name"
         << setw(20) << "Doctor_Name"
         << "Medications" << endl;

    for (const auto& p : prescriptions) {
        cout << setw(20) << p.prescription_id
             << setw(20) << p.patient_name
             << setw(20) << p.doctor_name
             << accumulate(p.medications.begin(), p.medications.end(), string(),
                [](string a, string b) { return a.empty() ? b : a + ", " + b; })
             << endl;
    }
    cout << endl;
}

void PrintDepartmentData(const vector<Department>& departments) {
    cout << left << setw(20) << "Department_Name"
         << setw(20) << "Head"
         << "Staff_Count" << endl;

    for (const auto& d : departments) {
        cout << setw(20) << d.name
             << setw(20) << d.head
             << d.staff_count << endl;
    }
    cout << endl;
}

void PrintStaffData(const vector<Staff>& staff) {
    cout << left << setw(20) << "Staff_Name"
         << setw(20) << "Role"
         << setw(20) << "Contact"
         << "Experience (Years)" << endl;

    for (const auto& s : staff) {
        cout << setw(20) << s.name
             << setw(20) << s.role
             << setw(20) << s.contact
             << s.experience << endl;
    }
    cout << endl;
}

void PrintEquipmentData(const vector<MedicalEquipment>& equipment) {
    cout << left << setw(20) << "Equipment_Name"
         << setw(20) << "Quantity"
         << "Status" << endl;

    for (const auto& e : equipment) {
        cout << setw(20) << e.equipment_name
             << setw(20) << e.quantity
             << e.status << endl;
    }
    cout << endl;
}

void PrintEmergencyContactData(const vector<EmergencyContact>& emergencyContacts) {
    cout << left << setw(20) << "Patient_Name"
         << setw(20) << "Contact_Name"
         << setw(20) << "Relationship"
         << "Contact_Number" << endl;

    for (const auto& ec : emergencyContacts) {
        cout << setw(20) << ec.patient_name
             << setw(20) << ec.contact_name
             << setw(20) << ec.relationship
             << ec.contact_number << endl;
    }
    cout << endl;
}

void PrintPatientHistoryData(const vector<PatientHistory>& histories) {
    cout << left << setw(20) << "Patient_Id"
         << "Medical_Conditions"
         << "Treatments" << endl;

    for (const auto& h : histories) {
        cout << setw(20) << h.patient_id << "         ";
        for (const auto& condition : h.medical_conditions) {
            cout << condition << " ";
        }
        cout << "         ";
        for (const auto& treatment : h.treatments) {
            cout << treatment << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Hospital Management Function
void HospitalManagement(
    string patient_Name[], int patient_Id[], string patient_Contact[],
    string hospital_Name[], string locations[], int beds[], float ratings[],
    string hospital_Contact[], string doctor_Name[], string doctor_specialization[],
    string doctor_contact[], float doctor_experience[])
{
    vector<Hospital> hospitals;
    vector<Patient> patients;
    vector<Doctor> doctors;
    vector<Appointment> appointments;
    vector<Bill> bills;
    vector<Prescription> prescriptions;
    vector<Department> departments;
    vector<Staff> staff;
    vector<MedicalEquipment> equipment;
    vector<EmergencyContact> emergencyContacts;
    vector<PatientHistory> histories;

    // Initialize Hospital data
    for (int i = 0; i < 4; i++) {
        Hospital h;
        h.H_name = hospital_Name[i];
        h.location = locations[i];
        h.available_beds = beds[i];
        h.rating = ratings[i];
        h.contact = hospital_Contact[i];
        h.doctor_name = doctor_Name[i];
        h.price = 200; // Example price
        hospitals.push_back(h);
    }

    // Initialize Patient data
    for (int i = 0; i < 4; i++) {
        Patient p;
        p.P_name = patient_Name[i];
        p.P_id = patient_Id[i];
        p.contact = patient_Contact[i];
        patients.push_back(p);
    }
// Initialize Doctor data
    for (int i = 0; i < 4; i++) {
        Doctor d;
        d.name = doctor_Name[i];
        d.specialization = doctor_specialization[i];
        d.contact = doctor_contact[i];
        d.experience = doctor_experience[i];
        doctors.push_back(d);
    }

    // Initialize Appointment data
    for (int i = 0; i < 4; i++) {
        Appointment a;
        a.appointment_id = i + 1;
        a.patient_name = patients[i].P_name;
        a.doctor_name = doctors[i].name;
        a.date_time = "2023-10-01 10:00"; // Example date
        appointments.push_back(a);
    }

    // Initialize Bill data
    for (int i = 0; i < 4; i++) {
        Bill b;
        b.bill_id = i + 1;
        b.patient_id = patients[i].P_id;
        b.amount = 200; // Example amount
        b.date = "2023-10-01"; // Example date
        bills.push_back(b);
    }

    // Initialize Prescription data
    for (int i = 0; i < 4; i++) {
        Prescription p;
        p.prescription_id = i + 1;
        p.patient_name = patients[i].P_name;
        p.doctor_name = doctors[i].name;
        p.medications = { "Med1", "Med2" }; // Example medications
        prescriptions.push_back(p);
    }

    // Initialize Department data
    for (int i = 0; i < 2; i++) {
        Department d;
        d.name = (i % 2 == 0) ? "Cardiology" : "Neurology";
        d.head = doctors[i].name;
        d.staff_count = 5; // Example count
        departments.push_back(d);
    }

    // Initialize Staff data
    for (int i = 0; i < 4; i++) {
        Staff s;
        s.name = "Staff" + to_string(i + 1);
        s.role = (i % 2 == 0) ? "Nurse" : "Technician";
        s.contact = "017XXXXXXXX" + to_string(i);
        s.experience = 3.0 + i; // Example experience
        staff.push_back(s);
    }

    // Initialize Medical Equipment data
    for (int i = 0; i < 4; i++) {
        MedicalEquipment e;
        e.equipment_name = "Equipment" + to_string(i + 1);
        e.quantity = 10 + i; // Example quantity
        e.status = (i % 2 == 0) ? "Available" : "Under Maintenance";
        equipment.push_back(e);
    }

    // Initialize Emergency Contact data
    for (int i = 0; i < 4; i++) {
        EmergencyContact ec;
        ec.patient_name = patients[i].P_name;
        ec.contact_name = "Contact" + to_string(i + 1);
        ec.relationship = (i % 2 == 0) ? "Sibling" : "Parent";
        ec.contact_number = "017XXXXXXXX" + to_string(i);
        emergencyContacts.push_back(ec);
    }

    // Initialize Patient History data
    for (int i = 0; i < 4; i++) {
        PatientHistory h;
        h.patient_id = patients[i].P_id;
        h.medical_conditions = { "Condition1", "Condition2" }; // Example conditions
        h.treatments = { "Treatment1", "Treatment2" }; // Example treatments
        histories.push_back(h);
    }

    // Print data
    PrintHospitalData(hospitals);
    PrintPatientData(patients);
    PrintDoctorData(doctors);
    PrintAppointmentData(appointments);
    PrintBillData(bills);
    PrintPrescriptionData(prescriptions);
    PrintDepartmentData(departments);
    PrintStaffData(staff);
    PrintEquipmentData(equipment);
    PrintEmergencyContactData(emergencyContacts);
    PrintPatientHistoryData(histories);
}

// Driver Code
int main() {
    string patient_Name[] = { "Rahim", "Karim", "Jamal", "Fatema" };
    int patient_Id[] = { 1, 2, 3, 4 };
    string patient_Contact[] = { "01812345678", "01823456789", "01834567890", "01845678901" };

    string hospital_Name[] = { "Dhaka Medical", "Rangpur Medical", "Chittagong Medical", "Rajshahi Medical" };
    string locations[] = { "Dhaka", "Rangpur", "Chittagong", "Rajshahi" };
    int beds[] = { 50, 60, 40, 30 };
    float ratings[] = { 4.5, 4.2, 4.0, 3.8 };
    string hospital_Contact[] = { "01887654321", "01898765432", "01987654321", "01998765432" };
    string doctor_Name[] = { "Dr. Ahmed", "Dr. Hasan", "Dr. Rahman", "Dr. Sultana" };
    string doctor_specialization[] = { "Cardiology", "Neurology", "Orthopedics", "Pediatrics" };
    string doctor_contact[] = { "0176543210", "0177654321", "0178765432", "0179876543" };
    float doctor_experience[] = { 10.0, 8.5, 6.2, 4.0 };

    // Function Call
    HospitalManagement(
        patient_Name, patient_Id, patient_Contact,
        hospital_Name, locations, beds, ratings, hospital_Contact,
        doctor_Name, doctor_specialization, doctor_contact, doctor_experience
    );

    return 0;
}

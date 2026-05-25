# 🧠 Object-Oriented MCQ Quiz Application (C++)

A highly structured, console-based **Multiple Choice Question (MCQ) Quiz Application** implemented in **C++** using strict **Object-Oriented Programming (OOP)** principles. The application loads question banks dynamically from external text files based on the user's chosen field and tracks performance seamlessly.



---

## ✨ Features

* **🧩 Domain-Driven Screen Inheritance:** Utilizes an abstract UI architecture (`clsScreen`) to dynamically inherit and render specialized category screens.
* **💾 Dynamic File-Based Question Banks:** Separates quizzes into independent text databases (`MathQuestions.txt`, `ProgrammingQuestions.txt`, `ScienceQuestions.txt`, `SportsQuestions.txt`) for scalable content management.
* **🎮 Categorized Gameplay:** Players can cleanly navigate via a main menu (`clsMainMenuScreen`) to choose their desired field of examination.
* **⚡ Polymorphic Evaluation:** Uses specialized question sub-classes (like `clsMathQuestion`, `clsHistoryQuestion`) to handle distinct validation algorithms per category.
* **📊 Live Score Tracking & Results:** Features active player profile management (`clsPlayer`) to calculate final scores, percentages, and performance summaries upon completing a quiz.
* **🛠️ Robust Helper Tools:** Integrated with fundamental string parsing (`clsString`), input handling validation (`clsInputValidate`), and system utilities (`clsUtil`).

---

## 📂 Project Architecture

The architecture decouples UI rendering, database files, and core game logic:

### 🗃️ Database Layer (Question Banks)
* `MathQuestions.txt`: List of multiple-choice mathematics questions and answers.
* `ProgrammingQuestions.txt`: Code-based engineering and logical syntax queries.
* `ScienceQuestions.txt`: General physics, chemistry, and biology assessments.
* `SportsQuestions.txt`: Global sports trivia and informational records.

### 🏛️ Core Business Logic Classes
* `clsQuestion`: The foundational model handling generic quiz question structures, choices, and answers.
* `clsPlayer`: Tracks individual player names, active sessions, and grading metrics.
* `clsMathQuestion` & `clsHistoryQuestion`: Specialized class variations providing category-specific behaviors.
* `clsInputValidate` & `clsString` & `clsDate` & `clsUtil`: Reusable utility classes managing input safety bounds and text formatting.

### 🖥️ Presentation Layer (UI Screens)
* `clsScreen`: The master layout blueprint defining unified design lines for the terminal interface.
* `clsMainMenuScreen`: Prompts users with category selection fields and coordinates navigation flows.
* `clsProgrammingQuestionsH` / `clsScienceQuestionsH` / `clsSportsQuestionsH`: Interactive display screens tailored to load and print specific question buffers cleanly.

---

## 🚀 How to Run the Project

1. **Clone the repository:**
   ```bash
   git clone [https://github.com/yousefwesam12/MCQ-Quiz-System.git](https://github.com/yousefwesam12/MCQ-Quiz-System.git)

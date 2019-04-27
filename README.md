# ENGG1340 **Group 67**
## Project name : Your financial Mojordomo

## About us
1. Yam Chak Fung Wesley
2. Chu Wai Kit
## **Part 1: Overview**
This part focuses on problem statement and problem setting. 
### **1. Problem statement**
   People nowadays often fail to plan on their own financial status. It creates many aftermaths in various aspects, say interpersonal relationship and qualiy of life. Todate, it is commmon to see brankruptcy due to some reasons, like overconsumption on leisurement.
 
  Undenibly, managing financial status is an essential skill for all of us. Recently many researches have shown the benefit of managing and planning since early stage. In light of this, we would like to develop an accounting system to help parents to inculcate their kids the concept of currency as well as helping teens to develop an useful habit.
  
  To achieve this, we have four main features to facilitate the use of the systems. They are basic financial managment, prediction/report, login function, task trigger. These will be discussed in the following sections. 
 
  In short, this system provides a spectrum of user-friendly, safe and efficient features to view, manage and track their kids' financial status. Thus, student can learn to plan better. As a result , we can promote a good econ-planning mindset to our next generation in a long term, contributing to the society. 
 
### **2. Problem setting**
1. How to make a user friendly environment to do management?
2. How to create a quick search and sort for our customers?
3. How to give our customers detailed report and prediction for their future?
4. How to make interation between parents and children?
5. How can we make a report for multiusers? -> 

## **Part 2: Functionalities and features**
  In this part, four main features - basic financial managment, prediction/report, login function, task trigger - will be discussed in detail one by one. 
 
### **1. Basic Financial Managment**

   #### 0 Before all
   **Warning**
   There is an main concept in our system which is we want to give the best, clear data to our targets. Therefore we want you to do somethings that causing you little time.
   
   **Important.** 
   You need to create the file of specific day before any further usage on our apps.
   
   ##### 0. Guide
   1. Say if you want to do something on 7th June
   2. You need to go main menu
   3. main menu-> 6. Initialization
   4. Enter 6 and type in (MMDD Format), which is 0607
   5. If you want to do functions in 12th Nov, you should enter 1112
   6  6 files is created
   7. Our format is username_date_scope.txt file.
   8  Say, mary_0427_food.txt
   9. Now, you can make use of our apps and read the followings.
   
   #### 1.1 Edit the menu
   -main menu->edit
   -There are **insert** , **remove** and **edit** function.
   -Force return to main menu if no file of specific day is found.
   
   ##### 1.1.1 Insert
   - main menu->edit->insert
   - There are 7 options.
   - Leave and 6 scopes for input data.
   - We will help you group the data into the format username_date_scope.txt file.
   - We also help you tag the items in chronological order.
   
   ###### 1.1.1 Insert -guild
   1. As normal, you need to enter the date for input.
   2. You need to enter the scope that you want to do insertion
   3. Enter the number of items you have bought that day
   4. Following by name,number of that item and price.
   5. If item size is larger than 10 or price is greater than 100, there will be a pop-up double validation.
   
   #### 1.1.2 Remove
   -main menu->edit->remove
   -7 options - leave and 6 scopes like insert
   -We will then count the removed price and re-calculate the sum of that scope. A new sum will be shown in the       username_date_scope.txt file.
   
   ##### 1.1.2 Remove-guide
   1. Refer Insert-guide 1-2
   2. You can enter multi-line that you want to remove
   3. After entering the unwanted line, enter 0 behind
   
   #### 1.1.3 Edit
   main menu->edit->edit
   -7  options - leave and 6 scopes.
   - It helps you to remodify the data.
   
   ##### 1. Edit Guide
   1. Refer to insert-guild rule 1-2
   2. You enter the problem line and re-enter the datas
   
  #### 1.2 - Search
  Fast accessibility on reading their files.
  
  ##### 1.2 Search Guide.
   1. Main menu->search
   2. Enter the date
   3. Enter the scope
   4. If you enter 7(ALL), you need to press y for reading next paper
  
  
  #### 1.3 - Sort
  - User-freindly sorting system.
  - Ascending and descending sort.(One of them)
  - Sort by price, number of specific items and name.(One of them)
  - You just need to enter the date and follow the black box.
  
  #### 1.4 - SetTasks
   Kids need to choose which tasks they've done and the pocket moeny will instantly store to the username_date_gain.txt. Then, they can ask their parents to gain their money after they finish the task.
   
   ##### SetTasks Guide
   1.  Only parents can assin task.
   2.  When childern done, they can go menu->task to remove the tasks
   3.  They can watch how many task they have not yet done in main menu
   4.  They need to enter the dates, then the income of that date will be increased by the bonus after mission.
   5    Of course, kids remember to get the recognision from parents after finsihing the tasks

  #### 1.5 - Deep Learning
  1.  Layer_network:  Affine1(fully connected)->ReLu->Affine2(fully connected)->softmax->entrophy loss
  2. We use classic backward popagation model and after these layers, the error can send back to train the prediction model.
  3. Since it takes a lot of training to get correct, the model maybe correct just after 100 dates.
  4. It is useded for long term prediciton
  5. We do not want the skipped data set, say you want to train from 1st Macch to 2rd Arpil, but you just have 1st april data, then the prediciton is not true with high possibility.
  
  #### 1.5 - DL guide
  - Main->7 deep learning
  - if you are first time to do deep learning
  - press y for deep learning initialization
  - press no otherwise
  -  Enter the first day
  - Enter the second day
  - The duration between these 2 days will be took for training datas.
  - Main->2 Report
  - Enter the first day
  - Enter today.
  - A prediction and accuracy from deep learing will be given.
  
#### 1.6 Report
   We will generate a daily report of specific date. The customers can also read their previous report in file. The function will be dicussed below.
   
##### Skilled fulfilled
   - Dynamic memory management(vector,link-list,array,class,struct,multi-inheritance,encapsulation)
   - File input/output(file in and out of the data)
   - Data manipulation such as sorting, searching, adding/editing/deleting data records (merge sort, selection sort, adding appending,delete edit)
   - Program codes in multiple files (25 cpp and h file)
   - Proper indentation and naming styles
   - In-code documentation
   
#### **2. Prediction/Report**
   - It reports you with the percentage and spenditure of specific region.  
   - The report contains the percentage and the total sum of each scope.
   - The precentage can tell the kids about their financial status statistically.
   - Then, we have mean prediction and deep learning prediction which will provide 2 kinds of prediction to kids.
     Hence, they can plan for next day easily.(short term prediction, long term prediciton)
      
### **3. Login Function**
As we mentioned, financial status is sensitive personal information. A secured login system to prevent unwanted users to access is essential. There are 4 options here. They are Login, Register, Forget and Exit repectively. The feasures is discussed one by one in the following  

#### 3.1 Multi-users
   -With the login system, we do support **multi-users**. 
   Say a family of 3 childrens, they can share the same computer but their documents will be separated. 

#### 3.2 Login
   - Input username
      The username exists -> a alert will pop out and user have to input again. 
   - Input the password. 
      **5 chances only**  considering the bot attack
   -Once the user input the username and corresponding password correctly, it shows "Welcome" and enters the main menu. 

#### 3.3 Register
   - Sign up for an account before they use the program. As it is open to the public. 
   - Input the username. 
      The username exists -> an alert 
   - Input the password
      For security reason and avoid unreasonally many data
      -> **Must be within 6-20 characters combining both characters and numbers** 
      -> Fouble validation to ensure users input the right password
   - After registeration -> notification shows up

#### 3.4 Forget
   - Considering users may forget their username and password
   - Input their email address here to find their data by entering their email address. 
      -> To avoid the invalid data, there is a **format check**. Any invalid email -> alert. 

#### 3.5 Exit
   - After you are done with the system, you can leave here :)

### **4. Task Trigger**
Since the purpose of this system is to let kids have a user-friendly, safe and efficient tool to manage financial status by themselves, parents also plays an important role. This function aims to have interactivity between parents and their children, allowing parents to provide some solid motivations to their kids. 
We use **linked list** to achieve this purpose for 2 reasons 
- The system can by better management on dynamic data structure as well as insertion and deletion. We have 5 features here. 

#### 4.1 Assign Task
   - Node for each task with 4 data. User need to input the first two.
      Task name -> Okay even it is a sentence, eg. "Do Homework"
      Bonus for completing the task
      True/Falso for the status of completing the task
      Next memory address
   - Double confirmation and ask for continuation
      Users simply type 'y' or 'n' to decide so it is more user-friendly. 

#### 4.2 View Task
Parents can check if tasks have finished or not here. Task name, bonus and status are all shown here. Moreover, if they wish to delete unwanted the task, they can simply input the line of the task. The **menu will be updated instantly**. The corresponding data in the memory will also be deleted at the same time to avoid data leak. 

#### 4.3 Initialize Task
This feature provides a **quick way to clear all the tasks**. Again, a double comfimation is required to prevent wrong input. 

#### 4.4 Sort Task
   - Only sorting by price is provide since it is not a easy way to sort a linked list
   - A special algorithom is used - **Merge Sort**. 
      It is preferred for sorting linked list because
      -> In linked list to access i th index 
          -> The system travels every node from the head to look for i th node as we don’t have continuous block of memory 
            -> Merge sort accesses data sequentially and the need of random access is low
               ->Thus **higher efficiency**. 

#### 4.5 Complete Task
   - Kids can view the task here. Task name, bonus and status are all shown here. 
   -> Finished the task -> simply input the line of the task
   - **The menu is updated at once** 
   - **The income will be recorded at the same time**. 

## **Part 3: How can I get started**
   - We can start by login.cpp and excute the file. 
   - The first step is to register -> login
   - If you forget your username or password, do not worry, you can input your email and we will contact you. 
   - After signing in, there are 2 modes 
   - Choose Children mode and Parents mode by entering 1 or 2. 

#### If you are parents
   - It is the mode for parents to modify the task
      Parents can assign / delete / sort tasks here
   - Enter 1 to assign tasks
      Enter the task name -> the bonus once the kid finished that task -> Double confirmation to ensure no mistake -> Ask to Continue 
   - Enter 2 to remove / view tasks
      Current tasks in "real time"
      If you remove any one of it -> the menu responses at the same time 
   - Enter 3 to sort tasks 
      If parents wish kids to finish some more urgent or valuable tasks first. 
   - Enter 0 to leave 
      They can comeback to modify anytime. 

#### If you are kids 
**Must Read**
For children mode, there are 7 options. 
**REMEMBER initialize(option 6), so that you can create a file of that day for futher usage**. For remaining options are easy to follow. **For deep learning part, you need to initialize it ONCE in deep learning menu or report menu for the FIRST time**. It will ask you if initialize. You just need to choose Yes **for the first time**, NO **for the future**.(very important, I recap it in  twice) The following shows you the way to initialize the system and the deep learning model.  

   ###### Guide : How to initialize
   - Login-> Kids-> 6.Initalize
   - Enter a date for setting of computer
   - Now you can do furthur application on the dates that you have been created before.
   
   ###### Guide : Deep learning initialize
   - Press y for first time seeing the pop-up

##### **Edit Your Wallet**
   - menu-> edit your wallet
   - Kid can insert, delete and edit their expense and income here. 
   - Enter the date in form of MMDD (eg. 1st of July -> 0701) 
      -> To delcare the specific date you wish to modify. 
   - Choose Insert / Remove / Edit
   - Choose the category
   - Enter the number of different items and then enter them one by one
      -> the name of the item -> number of the item -> total price -> Confirm :)
   - Be reminded that the total price means total sum of that price. 
   
##### **Report**
   - The report consists of two parts 
      The current date's report 
      The prediction
   - Input the date and category you wish to check
   - The screen will show the report 
   - A text file is generated for users for further usage

##### **Initialization on main menu**
   - Menu-> 6. Initialization
   - Create a new file for specific date

##### **Deep learning inititalization**
   - menu-> 7 Deep learning
   - menu -> 2 report
   - Setting for deep learning
   - We need to tell the computer to create a file for controlling the calculation
   - Once you do it, there will have a paper forever for controlling

##### **Re-Initialization on add/delete/edit menu**
   - menu->edit->insert/remove/edit-> Re-Initialization
   - To clear all data on specific date

##### **Sort** 
   - menu -> sort
   - You can Sort here. 

##### **Task trigger** 
   - Menu-> 4.Tasks
   - In the main menu, there will be a reminder **reminds you how many task to do**
   For example, if your parents assign 2 tasks, then show 1 tasks is waiting you'
   After you have done one of them -> Show '1 tasks is waiting you'
   - You can view tasks here 
   - If you have finish - select the line of that task. It will change from 'Doing' to 'Done' instantly. 

##### Common Questions
   1. What is inititalization?
   - Refer to Key concept
   - Menu-> 6. Initialization
   
   2. What is deep learning inititalization?
   - Refer to Key concept
   - Menu-> 7 Deep learning
   - Menu -> 2 report
   - Refer to key concept
   
   3. How to enter date in form of MMDD
   - We want you to give us month and day of specific date -> You can modify data from any date you want. 
   - For example :
      3rd July = 0703
      20th June = 0620
      12th Nov = 1112 

## **Part 4: Limitations**
1. Checkers have been added to avoid invaid input, say in the main menu, if users input any characters except 0- 7, an alert pops out. So we try to simplify the input by just entering a character or number. However, it is still impossible to include every exception case.  
2. Only standary library is allowed and being year 1 students, a lot of features do not work as we expected, like we made masking for the password and deep learning model for prediction, providing higher security and flexibility. Still, it is a precious opportunity for learning. 

3. Too few data. As deep learning model requires lot of data and time to train. Thus, the predicition is not accurate for now. However,  we do not have a database to collect and save that amounts of data methodically. It is still at a primary stage and we will enhance it in the future. 

4. Some codes are not compatible in Windons and Linux. Testing on both platforms has been done. However, there may be unexpected errors. Like, "cout << "\003[2J\033[1;1h" << endl;"

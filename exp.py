class Env(object):
    def __init__(self):
        print("Input clean OR dirty for the following Blocks")
        self.loc = {'A': 'clean', 'B': 'clean'}
        self.loc['A'] =  input("Enter for BLOCK A : ") 
        self.loc['B'] =  input("Enter for BLOCK B : ") 

class SimpleReflexVacuumAgent(Env):
    def __init__(self, Env):
        
        vacuumLocation =  input("Enter Vaccuum Location left(block A) or right(block B) : ")

        if(Env.loc['A'] == "clean" and Env.loc['B'] == "clean"):
            print("No operation !!")
            return

        if vacuumLocation == "left":
            print("Vacuum is placed at Location A.")
            
            if Env.loc['A'] == "dirty":
                print("Location A is Dirty. So, perform suck operation.")
               
                Env.loc['A'] = "clean"
                print("Location A has been Cleaned.")
               
                print("Moving to right...")

               
                if Env.loc['B'] == "dirty":
                    print("Location B is Dirty.")
                    
                    Env.loc['B'] = "clean"
                    print("Location B has been Cleaned.")
            else:
                
                print("Location A is Cleaned , So Moving to right...")
               
                if Env.loc['B'] == "dirty":
                    print("Location B is Dirty. So, perform suck operation.")
                    
                    Env.loc['B'] = "clean"
                    print("Location B has been Cleaned.")
                else:
                    print("Location B is Clean")    

        elif vacuumLocation == "right":
            print("Vacuum  placed at Location B.")
            
            if Env.loc['B'] == "dirty":
                print("Location B is Dirty.")
                
                Env.loc['B'] = "clean"
                print("Location B has been Cleaned.")
                
                print("Moving to left...")
                
                if Env.loc['A'] == "dirty":
                    print("Location A is Dirty.")
                   
                    Env.loc['A'] = "clean"
                    print("Location A has been Cleaned.")
            else:
               
                print("Location B is Cleaned , So Moving to left...")
                
                if Env.loc['A'] == "dirty":
                    print("Location A is Dirty.")
                    
                    Env.loc['A'] = "clean"
                    print("Location A has been Cleaned.")
                else:
                    print("Location A is cleaned")
        else:
            print("Please enter a valid input!")
            return
        
Environment = Env()
VacuumCleanerAgent = SimpleReflexVacuumAgent(Environment)
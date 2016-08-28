#include <PA9.h> 
#include <sys/dir.h>

bool fileLocator(char *start, char *target, bool isDir, int depth, char *result)
{
   struct stat st;
   DIR_ITER *dir = diropen(start);
   static char child[256];
   char temp[256];
   
   if (dir)
   {
      while (dirnext(dir, child, &st) == 0)
      {
         if (strlen(child) == 1 && child[0] == '.')
            continue;
                  
         if (strlen(child) == 2 && child[0] == '.' && child[1] == '.')
            continue;
         
         if (((st.st_mode & S_IFDIR) && isDir) || (!(st.st_mode & S_IFDIR) && !isDir) )
         {
            if (strcasecmp(target, child) == 0) // changed from strcmp to strcasecmp
            {
               strcpy(result, start);
               if (start[strlen(start)-1] != '/')
                  strcat(result, "/");

               strcat(result, child);
               if(isDir) // only add trailing slash if we're searching for a directory
                  strcat(result, "/");
            
               dirclose(dir);
               return true;
            }
         }
            
         if ((st.st_mode & S_IFDIR) && depth > 1)
         {
            strcpy(temp, start);
            if (start[strlen(start)-1] != '/')
               strcat(temp, "/");

            strcat(temp, child);
            strcat(temp, "/");
            
            if (fileLocator(temp, target, isDir, depth-1, result))
            {
               dirclose(dir);
               return true;
            }
         }
      }
   }
   
   dirclose(dir);
   return false;
} 

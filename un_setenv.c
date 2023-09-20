#include "main.h"
/**
 * _setenv - Set the value of an environment variable
 * @name: The name
 * @value: Value
 * @overwrite: over write
 * Return: 0/-1
 */
int _setenv(char *name, char *value, int overwrite)
{
size_t n_len = _cstrlen(name), v_len = _cstrlen(value), t_len;
char *env_var, **new_env, **env_ptr;
if (name == NULL || name[0] == '\0' || _strchr(name, '=') != NULL)
return (-1);
if (_cgetenv(name) != NULL && !overwrite)
return (0);
t_len = n_len + 1 + v_len + 1;
env_var = (char *)malloc(t_len);
if (env_var == NULL)
return (-1);
_cstrcpy(env_var, name);
env_var[n_len] = '=';
_cstrcpy(env_var + n_len + 1, value);
env_ptr = environ;
while (*env_ptr != NULL)
{
if (_cstrncmp(*env_ptr, name, n_len) == 0)
{
if (overwrite)
*env_ptr = env_var;
else
{
free(env_var);
return (0);
}
}
env_ptr++;
}
new_env = (char **)_realloc(environ, (env_ptr - environ + 2)
* sizeof(char *), (env_ptr - environ + 2) * sizeof(char *));
if (new_env == NULL)
{
free(env_var);
return (-1);
}
new_env[env_ptr - environ] = env_var;
new_env[env_ptr - environ + 1] = NULL;
environ = new_env;
return (0);
}

/**
 * _unsetenv - Unset an environment variable
 * @name: Name
 * Return: 0/-1
 */
int _unsetenv(const char *name)
{
char **env_ptr = environ;
char **new_env = NULL;
char **temp;
if (name == NULL || name[0] == '\0' || _strchr(name, '=') != NULL)
{
return (-1);
}
while (*env_ptr != NULL)
{
if (_cstrncmp(*env_ptr, name, _cstrlen(name)) == 0
&& (*env_ptr)[_cstrlen(name)] == '=')
{
env_ptr++;
}
else
{
temp = (char **)_realloc(new_env, (env_ptr - environ + 2)
* sizeof(char *), (env_ptr - environ + 2) * sizeof(char *));
if (temp == NULL)
{
free(new_env);
return (-1);
}
new_env = temp;
new_env[env_ptr - environ] = *env_ptr;
env_ptr++;
}
}
if (new_env != NULL)
{
new_env[env_ptr - environ] = NULL;
}
environ = new_env;
return (0);
}
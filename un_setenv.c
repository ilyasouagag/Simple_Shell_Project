#include "main.h"

/**
 * _setenv - Set the value of an environment variable
 * @name: The name
 * @value: Value
 * @n: over write 
 * Return: 0/-1
 */
int _setenv(char *name, char *value, int n) {
	size_t name_len;
	size_t value_len;
	size_t total_length;
	char *env_var;
	char **new_env;
	extern char **environ;
	char **env_ptr;
    if (name == NULL || name[0] == '\0' || _strchr(name, '=') != NULL) {
        return -1;
    }
    if (_getenv(name) != NULL && !n) {
        return 0;
    }
     name_len = _strlen(name);
     value_len = _strlen(value);
     total_length = name_len + 1 + value_len + 1; 
    env_var = (char *)malloc(total_length);
    if (env_var == NULL) {
        return -1;
    }
    _strcpy(env_var, name);
    env_var[name_len] = '=';
    _strcpy(env_var + name_len + 1, value);
	env_ptr = environ;
    while (*env_ptr != NULL) {
        if (_strncmp(*env_ptr, name, name_len) == 0) {
            if (n) {
                *env_ptr = env_var;
            } else {
                free(env_var);
                return 0;
            }
        }
        env_ptr++;
    }
    new_env = (char **)_realloc(environ, (env_ptr - environ + 2) * sizeof(char *), (env_ptr - environ + 2) * sizeof(char *));
    if (new_env == NULL) {
        free(env_var);
        return -1; 
    }
    new_env[env_ptr - environ] = env_var;
    new_env[env_ptr - environ + 1] = NULL;
    environ = new_env;
    return 0;
}

/**
 * _unsetenv - Unset an environment variable
 * @args: Args
 * Return: 0/-1
 */
int _unsetenv(char **args)
{
	char *name;
    char *msg2 = "unsetenv VARIABLE\n";
	if (args[1] == NULL)
	{
		write(1, msg2, _strlen(msg2));
		return (-1);
	}

	name = args[1];

	if (unsetenv(name) != 0)
	{
		perror("unsetenv");
	}
	return (0);
}
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
 _unsetenv(const char *name) {
    if (name == NULL || name[0] == '\0' || strchr(name, '=') != NULL) {
        return -1; // Invalid variable name
    }
	extern char **environ;
    char **env_ptr = environ;
    char **new_env = NULL;

    // Find the environment variable with the specified name
    while (*env_ptr != NULL) {
        if (strncmp(*env_ptr, name, strlen(name)) == 0 && (*env_ptr)[strlen(name)] == '=') {
            // Remove the matching variable by skipping it
            env_ptr++;
        } else {
            // Copy non-matching variables to the new_env array
            char **temp = (char **)realloc(new_env, (env_ptr - environ + 2) * sizeof(char *));
            if (temp == NULL) {
                // Memory reallocation failed
                free(new_env);
                return -1;
            }
            new_env = temp;
            new_env[env_ptr - environ] = *env_ptr;
            env_ptr++;
        }
    }

    // Terminate the new_env array
    if (new_env != NULL) {
        new_env[env_ptr - environ] = NULL;
    }

    // Update the environ pointer to the new environment
    environ = new_env;

    return 0; // Success
}
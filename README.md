
**[Libmacro](https://github.com/mcinglis/libmacro)** provides some useful C preprocessor macros:

- `ASSERT(...)` takes a series of scalar expressions and `assert()`s each one individually.

- `REQUIRE(...)` is similar to `ASSERT`, but it has a specific error message ("requirement unmet"), and it can be enabled and disabled separately. The intended usage of this is to define the requirements your functions have of their arguments; e.g. `REQUIRE(xs != NULL, n < xs.capacity)`.

- `NELEM(xs)` evaluates to a constant expression of the number of elements in the array variable `xs`.

- `ALLOC(Widget, .foo=42, .bar="wow")` provides an easy way to allocate memory with specific values, rather than having to do it in separate steps.

- `FREE(...)` takes a series of pointers to allocated memory, and `free()`s each one individually.

- `ANY(...)`, `ALL(...)`, and `NONE(...)` take a series of scalar expressions, and logically evaluate them according to the short-circuiting behavior of `&&` and `||`. For example, `ALL(a,b,c,d)` will only evaluate `a` and `b` if `c` is false.

- `DEBUG("value = %d", x)` provides an easy way to print debugging statements that include the file, line and function they were made on. If you find yourself regularly inserting `printf()` calls to work out what a program is doing, you'll find `DEBUG` very handy.

Read the header files for more documentation on the provided macros. See the [`tests/`](tests/) directory for example usage of the macros, and the expected output.

Note that the functions relying on Libpp for dealing with variable arguments (e.g. `REQUIRE` and `ANY`) can only take as many arguments as the limit that Libpp was built with - by default, this limit is 128. If you want to accept more or less, build Libpp with the `LIBPP_LIMIT` set to your desired value: e.g: `LIBPP_LIMIT=256 make -B libpp`.

[Questions](https://github.com/mcinglis/libmacro/issues?labels=question), [discussion](https://github.com/mcinglis/libmacro/issues?labels=discussion), [bug reports](https://github.com/mcinglis/libmacro/issues?labels=bug), [feature requests](https://github.com/mcinglis/libmacro/issues?labels=enhancement), and pull requests are very welcome.


## Releases

I'll tag the releases according to [semantic versioning](http://semver.org/spec/v2.0.0.html). All the macros preceded by `// @public`, or between `// @public begin` and `// @public end`, are considered public: they'll only change between major versions. The other macros could change any time. Non-preprocessor identifiers defined in header files are always considered public. New identifiers prefixed with `libmacro_` or `LIBMACRO_` will not warrant a major version bump.

Every version tag will be signed with [my GPG key](http://pool.sks-keyservers.net/pks/lookup?op=vindex&search=0xD020F814) (fingerprint: `0xD020F814`).


## Tests

```
$ make test
./tests/run.bash 2>/dev/null
pass: alloc
pass: assert
pass: debug
pass: logic
pass: nelem
pass: require
```


## Q&A

### What's all that dependency stuff in the Makefile?

It automates the fetching of the dependencies, checking out the right versions, and building them. In a similar way, you could specify Libmacro as a dependency, but override the `$DEPS_ROOT` environment variable to download it into the top-level directory. Then, dependents of Libmacro wouldn't need to know its dependencies, because its build process handles it. Dependencies are hidden and build processes are decoupled!

### Why don't you namespace this stuff?

These macros are totally generic and universally useful, so I don't see much need to specify their names as belonging to Libmacro. The likelihood of name clashes are low anyway, particularly since the headers are decoupled so that you can include them individually as you require.

If you really need a different name for an identifier, maintain a fork of the repository and pull updates from this one as you want them.

### Why don't you provide a header that includes everything?

I don't like unified headers, and I don't want to encourage their use. Unified headers:

- relieve the library developer of their responsibility to provide loosely-coupled modules clearly separated by their purpose and abstraction, and of the user to use those modules as such;
- make it harder to determine where a certain identifier came from;
- make code slower to compile and link.
- pollute the namespace, which can lead to all kinds of nasty bugs;
- make it harder to maintain API and ABI compatibility;

If you need to include six header files from Libmacro, your source file is probably doing too much, and should be broken up.


## License

**Copyright 2014 Malcolm Inglis <http://minglis.id.au>**

Libmacro is free software: you can redistribute it and/or modify it under the terms of the [GNU Affero General Public License](https://gnu.org/licenses/agpl.html) as published by the [Free Software Foundation](https://fsf.org), either version 3 of the License, or (at your option) any later version.

Libmacro is distributed in the hope that it will be useful, but **without any warranty**; without even the implied warranty of **merchantability** or **fitness for a particular purpose**. See the GNU Affero General Public License for more details.

You should have received a copy of the GNU Affero General Public License along with Libmacro. If not, see <https://gnu.org/licenses/>.

[Contact me](mailto:me@minglis.id.au) for commercial licensing options.

### Why AGPL?

[I believe that nonfree software is harmful](http://minglis.id.au/blog/2014/04/09/free-software-free-society.html), and I don't want to contribute to its development at all. I believe that a free society must necessarily operate on free software. I want to encourage the development of free software, and discourage the development of nonfree software.

The [GPL](https://gnu.org/licenses/gpl.html) was designed to ensure that the software stays free software; "to ensure that every user has freedom". The GPL's protections may have sufficed in 1990, but they don't in 2014. The GPL doesn't consider users of a web service to be users of the software implementing that server. Thankfully, the AGPL does.

The AGPL ensures that if Libmacro is used to implement a web service, then the entire source code of that web service must be free software. This way, I'm not contributing to nonfree software, whether it's executed locally or provided over a network.

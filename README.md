
**[Libmacro](https://github.com/mcinglis/libmacro)** provides some useful C preprocessor macros:

- `ASSERT(...)` takes a series of scalar expressions and `assert()`s each one individually.

- `REQUIRE(...)` is similar to `ASSERT`, but it has a specific error message ("requirement unmet"), and it can be enabled and disabled separately. The intended usage of this is to define the requirements your functions have of their arguments; e.g. `REQUIRE(xs != NULL, n < xs.capacity)`.

- `NELEM(xs)` evaluates to a constant expression of the number of elements in the array variable `xs`.

- `ALLOC(Widget, .foo=42, .bar="wow")` provides an easy way to allocate memory with specific values, rather than having to do it in separate steps.

- `FREE(...)` takes a series of pointers to allocated memory, and `free()`s each one individually.

- `ANY(...)`, `ALL(...)`, and `NONE(...)` take a series of scalar expressions, and logically evaluate them according to the short-circuiting behavior of `&&` and `||`. For example, `ALL(a,b,c,d)` will only evaluate `a`, `b` and `c` if `c` is false.

- `DEBUG("value = %d", x)` provides an easy way to print debugging statements that include the file, line and function they were made on. If you find yourself regularly inserting `printf()` calls to work out what a program is doing, you'll find `DEBUG` very handy.

- `SLICE( xs, 4, 3 )` evalutes to `xs[ 4 ], xs[ 5 ], xs[ 6 ]`; it makes it easier to map sections of one array to sections of another (or a struct).

Read the header files for more documentation on the provided macros. See the [`tests/`](tests/) directory for example usage of the macros, and the expected output.

Note that the functions relying on Libpp for dealing with variable arguments (e.g. `REQUIRE` and `ANY`) can only take as many arguments as the limit that Libpp was built with - by default, this limit is 128.


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
pass: slice
```


## Dependencies

`Package.json` specifies the dependencies of Libmacro: where to get them, and what version to use. I've developed a tool called [Puck](https://gitorious.org/mcinglis/puck) that will parse such a `Package.json`, download the specified repositories, check out the specified version, and, if the dependency has its own `Package.json`, repeat that process for *its* dependencies. With `puck` on your PATH, in the directory of Libmacro:

``` sh
$ puck update
$ puck execute build
```

There's nothing magic to what Puck does, so if you would prefer, you can perform those steps manually. You just need to have the dependencies in the `deps` directory within the Libmacro directory, and have them built (if necessary) before building Libmacro.


## Collaboration

Libmacro is available at [Gitorious](https://gitorious.org/mcinglis/libmacro), [Bitbucket](https://bitbucket.org/mcinglis/libmacro), and [GitHub](https://github.com/mcinglis/libmacro).

Questions, discussion, bug reports and feature requests are welcome at [the GitHub issue tracker](https://github.com/mcinglis/libmacro/issues), or via [emails](mailto:me@minglis.id.au).

To contribute changes, you're welcome to [email me](mailto:me@minglis.id.au) patches as per `git format-patch`, or to send me a pull request on any of the aforementioned sites. You're also welcome to just send me a link to your remote repository, and I'll merge stuff from that as I want to.

To accept notable contributions, I'll require you to assign your copyright to me. In your email/pull request and commit messages, please insert: "*I hereby irrevocably transfer to Malcolm Inglis (http://minglis.id.au) all copyrights, title, and interest, throughout the world, in these contributions to Libmacro*". If you can, please sign the email or pull request, ensuring your GPG key is publicly available.


## Q&A

### Why don't you namespace this stuff?

These macros are generic and universally useful, so I don't any need to specify their names as belonging to Libmacro. It would be semantically awkward. The likelihood of name clashes are low anyway, particularly since the headers are decoupled so that you can include them individually as you require. Similarly, it should be fairly obvious where each macro came from.

If you really need a different name for an identifier, maintain a fork of the repository and pull updates from this one as you want them.

### Why don't you provide a header that includes everything?

I don't like unified headers, and I don't want to encourage their use. Unified headers:

- relieve the library developer of their responsibility to provide loosely-coupled modules clearly separated by their purpose and abstraction, and of the user to use those modules as such;
- make it harder to determine where a certain identifier came from;
- make code slower to compile and link.
- pollute the namespace, which can lead to all kinds of nasty bugs;
- make it harder to maintain API and ABI compatibility.

If you need to include six header files from Libmacro, your source file is probably doing too much, and should be broken up.


## License

**Copyright 2014 Malcolm Inglis <http://minglis.id.au>**

Libmacro is free software: you can redistribute it and/or modify it under the terms of the [GNU Affero General Public License](https://gnu.org/licenses/agpl.html) as published by the [Free Software Foundation](https://fsf.org), either version 3 of the License, or (at your option) any later version.

Libmacro is distributed in the hope that it will be useful, but **without any warranty**; without even the implied warranty of **merchantability** or **fitness for a particular purpose**. See the GNU Affero General Public License for more details.

You should have received a copy of the GNU Affero General Public License along with Libmacro. If not, see <https://gnu.org/licenses/>.

[Contact me](mailto:me@minglis.id.au) for proprietary licensing options.

### Why AGPL?

[I believe that nonfree software is harmful](http://minglis.id.au/blog/2014/04/09/free-software-free-society.html), and I don't want to contribute to its development at all. I believe that a free society must necessarily operate on free software. I want to encourage the development of free software, and discourage the development of nonfree software.

The [GPL](https://gnu.org/licenses/gpl.html) was designed to ensure that the software stays free software; "to ensure that every user has freedom". The GPL's protections may have sufficed in 1990, but they don't in 2014. The GPL doesn't consider users of a web service to be users of the software implementing that server. Thankfully, the AGPL does.

The AGPL ensures that if Libmacro is used to implement a web service, then the entire source code of that web service must be free software. This way, I'm not contributing to nonfree software, whether it's executed locally or provided over a network.


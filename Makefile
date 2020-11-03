help:
	@echo "Tasks for local development:"
	@echo "* tests-config-single-ci:            Run a single config test from inside the CI"
	@echo "* tests-config-single-local:         Run a single config test locally"
	@echo "* tests-config-single-local-docker:  Run a single config test locally, using docker-compose"
	@echo "* tests-config-all-local:            Run all config tests locally"
	@echo "* tests-config-all-local-docker:     Run all config tests locally, using docker-compose"
	@echo "* tests-code-single-ci:              Run a single code test from inside the CI"
	@echo "* tests-code-single-local:           Run a single code test locally"
	@echo "* tests-code-single-local-docker:    Run a single code test locally, using docker-compose"
	@echo "* tests-code-all-local:              Run all code tests locally"
	@echo "* tests-code-all-local-docker:       Run all code tests locally, using docker-compose"
	@echo "* setup-local-docker:                Setup local docker-compose"
	@echo ""
	@echo "Options for testing:"
	@echo "  TEST_TARGET          Set when running tests-single-*, to select the"
	@echo "                       test. If you set it to ALL it will run all "
	@echo "                       tests, but some of them are broken: use "
	@echo "                       tests-all-* instead to run only the ones that "
	@echo "                       run on GitHub CI"
	@echo "  ONLY_TEST            Limit tests to only those that contain this, or
	@echo "                       the index of the test (1-based)"
	@echo "  VERBOSE_PLATFORMIO   If you want the full PIO output, set any value"
	@echo "  GIT_RESET_HARD       Used by CI: reset all local changes. WARNING:"
	@echo "                       THIS WILL UNDO ANY CHANGES YOU'VE MADE!"
.PHONY: help

tests-config-single-ci:
	export GIT_RESET_HARD=true
	$(MAKE) tests-config-single-local TEST_TARGET=$(TEST_TARGET)
.PHONY: tests-config-single-ci

tests-config-single-local:
	@if ! test -n "$(TEST_TARGET)" ; then echo "***ERROR*** Set TEST_TARGET=<your-module> or use make tests-config-all-local" ; return 1; fi
	export PATH=./buildroot/bin/:./buildroot/tests/:${PATH} \
	  && export VERBOSE_PLATFORMIO=$(VERBOSE_PLATFORMIO) \
	  && run_tests . $(TEST_TARGET) "$(ONLY_TEST)"
.PHONY: tests-config-single-local

tests-config-single-local-docker:
	@if ! test -n "$(TEST_TARGET)" ; then echo "***ERROR*** Set TEST_TARGET=<your-module> or use make tests-config-all-local-docker" ; return 1; fi
	docker-compose run --rm marlin $(MAKE) tests-single-local TEST_TARGET=$(TEST_TARGET) VERBOSE_PLATFORMIO=$(VERBOSE_PLATFORMIO) GIT_RESET_HARD=$(GIT_RESET_HARD) ONLY_TEST="$(ONLY_TEST)"
.PHONY: tests-config-single-local-docker

tests-config-all-local:
	export PATH=./buildroot/bin/:./buildroot/tests/:${PATH} \
	  && export VERBOSE_PLATFORMIO=$(VERBOSE_PLATFORMIO) \
	  && for TEST_TARGET in $$(./get_test_targets.py) ; do echo "Running tests for $$TEST_TARGET" ; run_tests . $$TEST_TARGET ; done
.PHONY: tests-config-all-local

tests-config-all-local-docker:
	docker-compose run --rm marlin $(MAKE) tests-all-local VERBOSE_PLATFORMIO=$(VERBOSE_PLATFORMIO) GIT_RESET_HARD=$(GIT_RESET_HARD)
.PHONY: tests-config-all-local-docker

tests-code-single-ci:
	export GIT_RESET_HARD=true
	$(MAKE) tests-code-single-local TEST_TARGET=$(TEST_TARGET)
.PHONY: tests-code-single-ci

# TODO: How can we limit tests with ONLY_TEST with platformio?
tests-code-single-local:
	@if ! test -n "$(TEST_TARGET)" ; then echo "***ERROR*** Set TEST_TARGET=<your-module> or use make tests-code-all-local" ; return 1; fi
	export PATH=./buildroot/bin/:./buildroot/tests/:${PATH} \
	  && export VERBOSE_PLATFORMIO=$(VERBOSE_PLATFORMIO) \
	  && exec_pio_test $(TEST_TARGET)
.PHONY: tests-code-single-local

tests-code-single-local-docker:
	@if ! test -n "$(TEST_TARGET)" ; then echo "***ERROR*** Set TEST_TARGET=<your-module> or use make tests-code-all-local-docker" ; return 1; fi
	docker-compose run --rm marlin $(MAKE) tests-code-single-local TEST_TARGET=$(TEST_TARGET) VERBOSE_PLATFORMIO=$(VERBOSE_PLATFORMIO) GIT_RESET_HARD=$(GIT_RESET_HARD) ONLY_TEST="$(ONLY_TEST)"
.PHONY: tests-code-single-local-docker

tests-code-all-local:
	export PATH=./buildroot/bin/:./buildroot/tests/:${PATH} \
	  && export VERBOSE_PLATFORMIO=$(VERBOSE_PLATFORMIO) \
	  && exec_all_pio_tests
.PHONY: tests-code-all-local

tests-code-all-local-docker:
	docker-compose run --rm marlin $(MAKE) tests-code-all-local VERBOSE_PLATFORMIO=$(VERBOSE_PLATFORMIO) GIT_RESET_HARD=$(GIT_RESET_HARD)
.PHONY: tests-code-all-local-dockerS

setup-local-docker:
	docker-compose build
.PHONY: setup-local-docker

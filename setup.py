
# This is not a normal 'setup.py' script; it is provided as a
# convenience to install Python packages required by Exchanger.  For
# instructions on installing Exchanger itself, see the file INSTALL.

from ez_setup import use_setuptools
use_setuptools()

from setuptools import setup
import sys

setup(
    script_args = (
    ['easy_install',
     '--find-links=svn://geodynamics.org/cig/cs/pythia/trunk#egg=pythia-dev'] +
    sys.argv[1:] +
    ['pythia >= 0.8-1.0dev-r4617, < 0.8-2.0a, == dev']
    )
)

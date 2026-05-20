/* ===== 23e876760 workers.fishing.memory_fish_read:63 ===== */
/* ghidra_name=FUN_23e876760 entry=23e876760 size=2935 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong * FUN_23e876760(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 *puVar6;
  longlong *plVar7;
  longlong *plVar8;
  code *pcVar9;
  int iVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong lVar13;
  longlong *plVar14;
  longlong *plVar15;
  longlong *plVar16;
  longlong *plVar17;
  longlong *plVar18;
  longlong *plVar19;
  undefined4 uVar20;
  longlong *plStack_78;
  longlong *plStack_70;
  longlong *plStack_68;
  longlong *plStack_60;
  longlong *plStack_58;
  
  plVar11 = _DAT_23eedeb90;
  plVar1 = (longlong *)*param_3;
  plVar2 = (longlong *)param_3[1];
  plVar3 = (longlong *)param_3[2];
  if (_DAT_23eedeb90 == (longlong *)0x0) {
LAB_23e8767a5:
    _DAT_23eedeb90 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eedeb88,DAT_23eedebc0,0x28);
  }
  else {
    lVar13 = *_DAT_23eedeb90;
    if (1 < lVar13) {
      *_DAT_23eedeb90 = lVar13 + -1;
      goto LAB_23e8767a5;
    }
    if (_DAT_23eedeb90[2] != 0) {
      *_DAT_23eedeb90 = lVar13 + -1;
      if (lVar13 + -1 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      goto LAB_23e8767a5;
    }
  }
  plVar7 = _DAT_23eedeb90;
  lVar13 = *(longlong *)(param_1 + 0x38);
  plVar11 = _DAT_23eedeb90 + 9;
  lVar4 = *(longlong *)(lVar13 + 8);
  _DAT_23eedeb90[0xf] = lVar4;
  *(longlong **)(lVar13 + 8) = plVar11;
  if ((lVar4 != 0) &&
     (((*(char *)(lVar4 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar4 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar4 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar4 + 0x38))
       ) && (plVar7[0xe] != 0)))) {
    plVar11 = *(longlong **)(lVar4 + 0x28);
    *(longlong **)(plVar7[0xe] + 0x10) = plVar11;
    if (plVar11 != (longlong *)0x0) {
      *plVar11 = *plVar11 + 1;
    }
  }
  *plVar7 = *plVar7 + 1;
  *(undefined4 *)(plVar7 + 8) = 0;
  if ((DAT_23ed8fb50 == 0) && (DAT_23ed8fb50 = PyImport_ImportModule("ctypes"), DAT_23ed8fb50 == 0))
  {
LAB_23e876d20:
    DAT_23ed8fb50 = 0;
    FUN_23e9364c0("%s : %s\n","IMPORT_HARD_CTYPES",
                  "\"Unexpected failure of hard import of \'ctypes\'\"");
                    /* WARNING: Subroutine does not return */
    abort();
  }
  lVar13 = DAT_23ed8fb50;
  *(undefined4 *)(plVar7 + 5) = 0x40;
  plVar11 = (longlong *)FUN_23e915840(param_1,lVar13,_DAT_23eeddc30,plVar3);
  if (plVar11 == (longlong *)0x0) {
    plVar16 = *(longlong **)(param_1 + 0x60);
    plVar19 = *(longlong **)(param_1 + 0x70);
    plVar12 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar20 = 0x40;
    plVar8 = *(longlong **)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar18 = DAT_23ed6a4f8;
    goto joined_r0x00023e876d83;
  }
  if ((DAT_23ed8fb50 == 0) && (DAT_23ed8fb50 = PyImport_ImportModule("ctypes"), DAT_23ed8fb50 == 0))
  goto LAB_23e876d20;
  lVar4 = _DAT_23eeddc40;
  lVar13 = DAT_23ed8fb50;
  *(undefined4 *)(plVar7 + 5) = 0x41;
  plVar12 = (longlong *)FUN_23e915840(param_1,lVar13,_DAT_23eeddc38,*(undefined8 *)(lVar4 + 0x18));
  if (plVar12 == (longlong *)0x0) {
    plVar16 = *(longlong **)(param_1 + 0x60);
    plVar19 = *(longlong **)(param_1 + 0x70);
    uVar20 = 0x41;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar8 = *(longlong **)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar18 = DAT_23ed6a4f8;
  }
  else {
    lVar13 = FUN_23e8dd910();
    if (lVar13 == 0) {
      FUN_23e915740(param_1,&plStack_78,_DAT_23eeddc10);
      uVar20 = 0x42;
      plVar19 = plStack_68;
      plVar18 = DAT_23ed6a4f8;
      plVar16 = plStack_78;
      plVar8 = plStack_70;
    }
    else {
      plVar14 = (longlong *)FUN_23e8bc2f0(lVar13,_DAT_23eeddc48);
      if (plVar14 != (longlong *)0x0) {
        if ((DAT_23ed8fb50 == 0) &&
           (DAT_23ed8fb50 = PyImport_ImportModule("ctypes"), DAT_23ed8fb50 == 0))
        goto LAB_23e876d20;
        lVar13 = DAT_23ed8fb50;
        *(undefined4 *)(plVar7 + 5) = 0x42;
        plVar15 = (longlong *)FUN_23e915840(param_1,lVar13,_DAT_23eeddc50,plVar2);
        if (plVar15 == (longlong *)0x0) {
          plVar16 = *(longlong **)(param_1 + 0x60);
          plVar19 = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          uVar20 = 0x42;
          plVar8 = *(longlong **)(param_1 + 0x68);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *plVar14 = *plVar14 + -1;
          plVar18 = DAT_23ed6a4f8;
          if (*plVar14 == 0) {
            (**(code **)(plVar14[1] + 0x30))(plVar14);
            uVar20 = 0x42;
            plVar18 = DAT_23ed6a4f8;
          }
          goto joined_r0x00023e876d83;
        }
        if ((DAT_23ed8fb50 == 0) &&
           (DAT_23ed8fb50 = PyImport_ImportModule("ctypes"), DAT_23ed8fb50 == 0))
        goto LAB_23e876d20;
        lVar13 = DAT_23ed8fb50;
        *(undefined4 *)(plVar7 + 5) = 0x42;
        plVar16 = (longlong *)FUN_23e915840(param_1,lVar13,_DAT_23eeddc58,plVar12);
        if (plVar16 == (longlong *)0x0) {
          plVar16 = *(longlong **)(param_1 + 0x60);
          plVar19 = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          plVar8 = *(longlong **)(param_1 + 0x68);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *plVar14 = *plVar14 + -1;
          if (*plVar14 == 0) {
            (**(code **)(plVar14[1] + 0x30))(plVar14);
          }
          *plVar15 = *plVar15 + -1;
          uVar20 = 0x42;
          plVar18 = DAT_23ed6a4f8;
          if (*plVar15 == 0) {
            (**(code **)(plVar15[1] + 0x30))(plVar15);
            uVar20 = 0x42;
            plVar18 = DAT_23ed6a4f8;
          }
          goto joined_r0x00023e876d83;
        }
        *(undefined4 *)(plVar7 + 5) = 0x42;
        plStack_78 = plVar1;
        plStack_70 = plVar15;
        plStack_68 = plVar11;
        plStack_60 = plVar3;
        plStack_58 = plVar16;
        plVar17 = (longlong *)FUN_23e95b390(param_1,plVar14,&plStack_78);
        *plVar14 = *plVar14 + -1;
        if (*plVar14 == 0) {
          (**(code **)(plVar14[1] + 0x30))(plVar14);
        }
        *plVar15 = *plVar15 + -1;
        if (*plVar15 == 0) {
          (**(code **)(plVar15[1] + 0x30))(plVar15);
        }
        *plVar16 = *plVar16 + -1;
        if (*plVar16 == 0) {
          (**(code **)(plVar16[1] + 0x30))(plVar16);
        }
        if (plVar17 != (longlong *)0x0) {
          iVar10 = FUN_23a35f020(plVar17);
          lVar13 = *plVar17 + -1;
          if (iVar10 == -1) {
            plVar16 = *(longlong **)(param_1 + 0x60);
            plVar19 = *(longlong **)(param_1 + 0x70);
            uVar20 = 0x42;
            *(undefined8 *)(param_1 + 0x70) = 0;
            plVar8 = *(longlong **)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *plVar17 = lVar13;
            plVar18 = DAT_23ed6a4f8;
            if (lVar13 == 0) {
              (**(code **)(plVar17[1] + 0x30))(plVar17);
              uVar20 = 0x42;
              plVar18 = DAT_23ed6a4f8;
            }
          }
          else {
            *plVar17 = lVar13;
            if (lVar13 == 0) {
              (**(code **)(plVar17[1] + 0x30))(plVar17);
            }
            if (iVar10 == 0) {
              lVar13 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
              plVar7 = *(longlong **)(lVar13 + 0x28);
              plVar16 = (longlong *)plVar7[2];
              *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar13 + 0x30);
              *(undefined4 *)(plVar7 + 8) = 0xffffffff;
              if (plVar16 != (longlong *)0x0) {
                plVar7[2] = 0;
                *plVar16 = *plVar16 + -1;
                if (*plVar16 == 0) {
                  (**(code **)(plVar16[1] + 0x30))();
                }
              }
              *plVar7 = *plVar7 + -1;
              if (*plVar7 == 0) {
                (**(code **)(plVar7[1] + 0x30))(plVar7);
              }
              plVar7[0xf] = 0;
              plVar16 = DAT_23ed6cd30;
              *DAT_23ed6cd30 = *DAT_23ed6cd30 + 1;
LAB_23e876c7e:
              *plVar11 = *plVar11 + -1;
              if (*plVar11 == 0) {
                (**(code **)(plVar11[1] + 0x30))(plVar11);
              }
              *plVar12 = *plVar12 + -1;
              if (*plVar12 == 0) {
                (**(code **)(plVar12[1] + 0x30))(plVar12);
              }
              *plVar1 = *plVar1 + -1;
              if (*plVar1 == 0) {
                (**(code **)(plVar1[1] + 0x30))(plVar1);
              }
              *plVar2 = *plVar2 + -1;
              if (*plVar2 == 0) {
                (**(code **)(plVar2[1] + 0x30))(plVar2);
              }
              *plVar3 = *plVar3 + -1;
              if (*plVar3 != 0) {
                return plVar16;
              }
              (**(code **)(plVar3[1] + 0x30))(plVar3);
              return plVar16;
            }
            plVar14 = (longlong *)FUN_23e8bc2f0(plVar11,_DAT_23eeddc60);
            if (plVar14 != (longlong *)0x0) {
              plVar16 = (longlong *)FUN_23e8bc2f0(plVar12,_DAT_23eeddc68);
              if (plVar16 == (longlong *)0x0) {
                plVar16 = *(longlong **)(param_1 + 0x60);
                plVar19 = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                uVar20 = 0x43;
                plVar8 = *(longlong **)(param_1 + 0x68);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                *plVar14 = *plVar14 + -1;
                plVar18 = DAT_23ed6a4f8;
                if (*plVar14 == 0) {
                  (**(code **)(plVar14[1] + 0x30))(plVar14);
                  uVar20 = 0x43;
                  plVar18 = DAT_23ed6a4f8;
                }
                goto joined_r0x00023e876d83;
              }
              plVar19 = *(longlong **)(*(longlong *)(param_1 + 0x10) + 0xe10);
              if (plVar19 == (longlong *)0x0) {
                plVar19 = (longlong *)FUN_23a33a530(PySlice_Type_exref);
              }
              else {
                *(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0xe10) = 0;
                *plVar19 = 1;
              }
              pcVar9 = _Py_NoneStruct_exref;
              *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 2;
              lVar13 = *plVar16;
              plVar19[4] = (longlong)pcVar9;
              plVar19[2] = (longlong)pcVar9;
              *plVar16 = lVar13 + 1;
              pcVar9 = _PyRuntime_exref;
              plVar19[3] = (longlong)plVar16;
              lVar4 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar9 + 0x1f8) + 0x10) + 0x2e8);
              lVar5 = plVar19[-1];
              puVar6 = *(undefined8 **)(lVar4 + 8);
              *puVar6 = plVar19 + -2;
              plVar19[-2] = lVar4;
              plVar19[-1] = (ulonglong)((uint)lVar5 & 3) | (ulonglong)puVar6;
              *(longlong **)(lVar4 + 8) = plVar19 + -2;
              *plVar16 = lVar13;
              if (lVar13 == 0) {
                (**(code **)(plVar16[1] + 0x30))(plVar16);
              }
              plVar16 = (longlong *)FUN_23a38cc10(param_1,plVar14);
              *plVar14 = *plVar14 + -1;
              if (*plVar14 == 0) {
                (**(code **)(plVar14[1] + 0x30))(plVar14);
              }
              *plVar19 = *plVar19 + -1;
              if (*plVar19 == 0) {
                (**(code **)(plVar19[1] + 0x30))(plVar19);
              }
              if (plVar16 != (longlong *)0x0) {
                lVar13 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                plVar7 = *(longlong **)(lVar13 + 0x28);
                plVar19 = (longlong *)plVar7[2];
                *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar13 + 0x30);
                *(undefined4 *)(plVar7 + 8) = 0xffffffff;
                if (plVar19 != (longlong *)0x0) {
                  plVar7[2] = 0;
                  *plVar19 = *plVar19 + -1;
                  if (*plVar19 == 0) {
                    (**(code **)(plVar19[1] + 0x30))();
                  }
                }
                *plVar7 = *plVar7 + -1;
                if (*plVar7 == 0) {
                  (**(code **)(plVar7[1] + 0x30))(plVar7);
                }
                plVar7[0xf] = 0;
                goto LAB_23e876c7e;
              }
            }
            plVar16 = *(longlong **)(param_1 + 0x60);
            plVar19 = *(longlong **)(param_1 + 0x70);
            uVar20 = 0x43;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar18 = DAT_23ed6a4f8;
            plVar8 = *(longlong **)(param_1 + 0x68);
          }
          goto joined_r0x00023e876d83;
        }
      }
      plVar16 = *(longlong **)(param_1 + 0x60);
      plVar19 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar20 = 0x42;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar18 = DAT_23ed6a4f8;
      plVar8 = *(longlong **)(param_1 + 0x68);
    }
  }
joined_r0x00023e876d83:
  DAT_23ed6a4f8 = plVar18;
  if (plVar19 == (longlong *)0x0) {
    if (plVar18 == (longlong *)0x0) {
      plVar18 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar18;
      *plVar18 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar9 = _PyRuntime_exref;
    plVar18[2] = 0;
    plVar18[3] = (longlong)plVar7;
    *plVar7 = *plVar7 + 1;
    lVar13 = *(longlong *)(pcVar9 + 0x1f8);
    *(undefined4 *)((longlong)plVar18 + 0x24) = uVar20;
    lVar13 = *(longlong *)(lVar13 + 0x10);
    *(undefined4 *)(plVar18 + 4) = 0xffffffff;
    lVar13 = *(longlong *)(lVar13 + 0x2e8);
    lVar4 = plVar18[-1];
    puVar6 = *(undefined8 **)(lVar13 + 8);
    *puVar6 = plVar18 + -2;
    plVar18[-2] = lVar13;
    plVar18[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar6;
    *(longlong **)(lVar13 + 8) = plVar18 + -2;
    plVar14 = plVar18;
  }
  else {
    plVar14 = plVar19;
    if ((longlong *)plVar19[3] != plVar7) {
      if (plVar18 == (longlong *)0x0) {
        plVar18 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        DAT_23ed6a4f8 = (longlong *)*plVar18;
        *plVar18 = 1;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      pcVar9 = _PyRuntime_exref;
      plVar18[3] = (longlong)plVar7;
      *plVar7 = *plVar7 + 1;
      lVar13 = *(longlong *)(pcVar9 + 0x1f8);
      *(undefined4 *)((longlong)plVar18 + 0x24) = uVar20;
      *(undefined4 *)(plVar18 + 4) = 0xffffffff;
      lVar13 = *(longlong *)(*(longlong *)(lVar13 + 0x10) + 0x2e8);
      lVar4 = plVar18[-1];
      puVar6 = *(undefined8 **)(lVar13 + 8);
      *puVar6 = plVar18 + -2;
      plVar18[-2] = lVar13;
      plVar18[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar6;
      lVar4 = *plVar19;
      *(longlong **)(lVar13 + 8) = plVar18 + -2;
      plVar18[2] = (longlong)plVar19;
      plVar14 = plVar18;
      if (lVar4 == 0) {
        (**(code **)(plVar19[1] + 0x30))(plVar19);
      }
    }
  }
  FUN_23e8bba40(plVar7,"ooooo",plVar1,plVar2,plVar3,plVar11,plVar12);
  if (_DAT_23eedeb90 == plVar7) {
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      (**(code **)(plVar7[1] + 0x30))(plVar7);
    }
    _DAT_23eedeb90 = (longlong *)0x0;
  }
  lVar13 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar7 = *(longlong **)(lVar13 + 0x28);
  plVar19 = (longlong *)plVar7[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar13 + 0x30);
  *(undefined4 *)(plVar7 + 8) = 0xffffffff;
  if (plVar19 != (longlong *)0x0) {
    plVar7[2] = 0;
    *plVar19 = *plVar19 + -1;
    if (*plVar19 == 0) {
      (**(code **)(plVar19[1] + 0x30))();
    }
  }
  *plVar7 = *plVar7 + -1;
  if (*plVar7 == 0) {
    (**(code **)(plVar7[1] + 0x30))(plVar7);
  }
  plVar7[0xf] = 0;
  if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  *plVar3 = *plVar3 + -1;
  if (*plVar3 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  FUN_23a33aa70(param_1,plVar16,plVar8,plVar14);
  return (longlong *)0x0;
}

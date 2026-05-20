/* ===== 23e2af890 ui.garbage_settings_dialog:c1197 ===== */
/* ghidra_name=FUN_23e2af890 entry=23e2af890 size=2022 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e2af890(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *plVar4;
  longlong *plVar5;
  undefined8 *puVar6;
  longlong *plVar7;
  char cVar8;
  int iVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  code *pcVar14;
  undefined8 uVar15;
  undefined4 uVar16;
  longlong lStack_50;
  
  plVar10 = _DAT_23eeb03a8;
  plVar1 = (longlong *)*param_3;
  if (_DAT_23eeb03a8 == (longlong *)0x0) {
LAB_23e2af8ca:
    _DAT_23eeb03a8 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eeb0480,DAT_23eeb0428,0x10);
  }
  else {
    lVar2 = *_DAT_23eeb03a8;
    if (1 < lVar2) {
      *_DAT_23eeb03a8 = lVar2 + -1;
      goto LAB_23e2af8ca;
    }
    if (_DAT_23eeb03a8[2] != 0) {
      *_DAT_23eeb03a8 = lVar2 + -1;
      if (lVar2 + -1 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      goto LAB_23e2af8ca;
    }
  }
  plVar7 = _DAT_23eeb03a8;
  lVar2 = *(longlong *)(param_1 + 0x38);
  plVar10 = _DAT_23eeb03a8 + 9;
  lVar3 = *(longlong *)(lVar2 + 8);
  _DAT_23eeb03a8[0xf] = lVar3;
  *(longlong **)(lVar2 + 8) = plVar10;
  if ((lVar3 != 0) &&
     (((*(char *)(lVar3 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar3 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar3 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar3 + 0x38))
       ) && (plVar7[0xe] != 0)))) {
    plVar10 = *(longlong **)(lVar3 + 0x28);
    *(longlong **)(plVar7[0xe] + 0x10) = plVar10;
    if (plVar10 != (longlong *)0x0) {
      *plVar10 = *plVar10 + 1;
    }
  }
  *plVar7 = *plVar7 + 1;
  uVar15 = DAT_23eeae440;
  *(undefined4 *)(plVar7 + 8) = 0;
  plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,uVar15);
  if (plVar10 == (longlong *)0x0) {
LAB_23e2afee3:
    plVar11 = (longlong *)0x0;
    lStack_50 = *(longlong *)(param_1 + 0x60);
    uVar15 = *(undefined8 *)(param_1 + 0x68);
    uVar16 = 0xde;
    plVar10 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar13 = DAT_23ed6a4f8;
  }
  else {
    plVar11 = (longlong *)FUN_23e8bc2f0(plVar10,_DAT_23eeae620);
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    if (plVar11 != (longlong *)0x0) {
      *(undefined4 *)(plVar7 + 5) = 0xde;
      plVar10 = (longlong *)FUN_23e91a870(param_1,plVar11);
      *plVar11 = *plVar11 + -1;
      if (*plVar11 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      if (plVar10 == (longlong *)0x0) goto LAB_23e2afee3;
      plVar12 = (longlong *)FUN_23ebf7180(plVar10);
      *plVar10 = *plVar10 + -1;
      if (*plVar10 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      plVar11 = (longlong *)0x0;
      if (plVar12 != (longlong *)0x0) {
        do {
          pcVar14 = *(code **)(plVar12[1] + 0xe0);
          if (pcVar14 == (code *)0x0) {
            PyErr_Format(*(undefined8 *)PyExc_TypeError_exref,"\'%s\' object is not an iterator",
                         *(undefined8 *)(plVar12[1] + 0x18));
LAB_23e2afd2b:
            cVar8 = FUN_23a3591a0(param_1,*(undefined8 *)PyExc_StopIteration_exref);
            if (cVar8 != '\0') {
              lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
              plVar10 = *(longlong **)(lVar2 + 0x28);
              plVar7 = (longlong *)plVar10[2];
              *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar2 + 0x30);
              *(undefined4 *)(plVar10 + 8) = 0xffffffff;
              if (plVar7 != (longlong *)0x0) {
                plVar10[2] = 0;
                *plVar7 = *plVar7 + -1;
                if (*plVar7 == 0) {
                  (**(code **)(plVar7[1] + 0x30))();
                }
              }
              *plVar10 = *plVar10 + -1;
              if (*plVar10 == 0) {
                (**(code **)(plVar10[1] + 0x30))(plVar10);
              }
              plVar10[0xf] = 0;
              if (plVar11 == (longlong *)0x0) {
                *plVar12 = *plVar12 + -1;
                if (*plVar12 == 0) {
                  (**(code **)(plVar12[1] + 0x30))(plVar12);
                }
                pcVar14 = _Py_NoneStruct_exref;
                *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
              }
              else {
                *plVar11 = *plVar11 + -1;
                if (*plVar11 == 0) {
                  (**(code **)(plVar11[1] + 0x30))(plVar11);
                }
                *plVar12 = *plVar12 + -1;
                if (*plVar12 == 0) {
                  (**(code **)(plVar12[1] + 0x30))(plVar12);
                }
                pcVar14 = _Py_NoneStruct_exref;
                *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
                *plVar11 = *plVar11 + -1;
                if (*plVar11 == 0) {
                  (**(code **)(plVar11[1] + 0x30))(plVar11);
                }
              }
              *plVar1 = *plVar1 + -1;
              if (*plVar1 != 0) {
                return pcVar14;
              }
              (**(code **)(plVar1[1] + 0x30))(plVar1);
              return pcVar14;
            }
            lStack_50 = *(longlong *)(param_1 + 0x60);
            uVar15 = *(undefined8 *)(param_1 + 0x68);
            plVar10 = *(longlong **)(param_1 + 0x70);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            if (plVar11 != (longlong *)0x0) goto LAB_23e2afb74;
            plVar11 = (longlong *)0x0;
            uVar16 = 0xde;
            goto LAB_23e2afb80;
          }
          plVar13 = (longlong *)(*pcVar14)(plVar12);
          if (plVar13 == (longlong *)0x0) goto LAB_23e2afd2b;
          if (plVar11 == (longlong *)0x0) {
            *plVar13 = *plVar13 + 1;
          }
          else {
            *plVar11 = *plVar11 + -1;
            if (*plVar11 == 0) {
              (**(code **)(plVar11[1] + 0x30))(plVar11);
              lVar2 = *plVar13;
            }
            else {
              lVar2 = *plVar13;
            }
            *plVar13 = lVar2 + 1;
            *plVar11 = *plVar11 + -1;
            if (*plVar11 == 0) {
              (**(code **)(plVar11[1] + 0x30))(plVar11);
            }
          }
          lVar2 = _DAT_23eeae638;
          *(undefined4 *)(plVar7 + 5) = 0xdf;
          plVar10 = (longlong *)
                    FUN_23e915840(param_1,plVar13,_DAT_23eeae628,*(undefined8 *)(lVar2 + 0x18));
          plVar11 = plVar13;
          if (plVar10 == (longlong *)0x0) {
            lStack_50 = *(longlong *)(param_1 + 0x60);
            uVar15 = *(undefined8 *)(param_1 + 0x68);
            uVar16 = 0xdf;
            plVar10 = *(longlong **)(param_1 + 0x70);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *plVar13 = *plVar13 + -1;
            lVar2 = *plVar13;
            goto joined_r0x00023e2b003c;
          }
          *plVar10 = *plVar10 + -1;
          if (*plVar10 == 0) {
            (**(code **)(plVar10[1] + 0x30))(plVar10);
          }
          lVar2 = *(longlong *)(param_1 + 0x10);
          if (((*(int *)(*(longlong *)(lVar2 + 0x28) + 0x160) != 0) || (*(int *)(lVar2 + 0x78) != 0)
              ) && ((iVar9 = Py_MakePendingCalls(), iVar9 < 0 &&
                    (lStack_50 = *(longlong *)(param_1 + 0x60), lStack_50 != 0))))
          goto LAB_23e2afb56;
          if (*(int *)(lVar2 + 0x68) == 0) {
            plVar10 = *(longlong **)(param_1 + 0x90);
          }
          else {
            PyEval_SaveThread();
            PyEval_AcquireThread(param_1);
            plVar10 = *(longlong **)(param_1 + 0x90);
          }
        } while (plVar10 == (longlong *)0x0);
        plVar13 = *(longlong **)(param_1 + 0x60);
        plVar4 = *(longlong **)(param_1 + 0x68);
        *(undefined8 *)(param_1 + 0x90) = 0;
        plVar5 = *(longlong **)(param_1 + 0x70);
        *(longlong **)(param_1 + 0x60) = plVar10;
        *plVar10 = *plVar10 + 1;
        *(undefined8 *)(param_1 + 0x68) = 0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
          (**(code **)(plVar13[1] + 0x30))();
        }
        if ((plVar4 != (longlong *)0x0) && (*plVar4 = *plVar4 + -1, *plVar4 == 0)) {
          (**(code **)(plVar4[1] + 0x30))(plVar4);
        }
        if ((plVar5 != (longlong *)0x0) && (*plVar5 = *plVar5 + -1, *plVar5 == 0)) {
          (**(code **)(plVar5[1] + 0x30))(plVar5);
        }
        lStack_50 = *(longlong *)(param_1 + 0x60);
LAB_23e2afb56:
        plVar10 = *(longlong **)(param_1 + 0x70);
        uVar15 = *(undefined8 *)(param_1 + 0x68);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e2afb74:
        uVar16 = 0xde;
        *plVar11 = *plVar11 + -1;
        lVar2 = *plVar11;
joined_r0x00023e2b003c:
        if (lVar2 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
LAB_23e2afb80:
        *plVar12 = *plVar12 + -1;
        plVar13 = DAT_23ed6a4f8;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
          plVar13 = DAT_23ed6a4f8;
        }
        goto joined_r0x00023e2afe30;
      }
    }
    lStack_50 = *(longlong *)(param_1 + 0x60);
    plVar10 = *(longlong **)(param_1 + 0x70);
    plVar11 = (longlong *)0x0;
    uVar15 = *(undefined8 *)(param_1 + 0x68);
    uVar16 = 0xde;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar13 = DAT_23ed6a4f8;
  }
joined_r0x00023e2afe30:
  DAT_23ed6a4f8 = plVar13;
  if (plVar10 == (longlong *)0x0) {
    if (plVar13 == (longlong *)0x0) {
      plVar13 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar13;
      *plVar13 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar14 = _PyRuntime_exref;
    plVar13[2] = 0;
    plVar13[3] = (longlong)plVar7;
    *plVar7 = *plVar7 + 1;
    lVar2 = *(longlong *)(pcVar14 + 0x1f8);
    *(undefined4 *)(plVar13 + 4) = 0xffffffff;
    lVar2 = *(longlong *)(lVar2 + 0x10);
    *(undefined4 *)((longlong)plVar13 + 0x24) = uVar16;
    lVar2 = *(longlong *)(lVar2 + 0x2e8);
    lVar3 = plVar13[-1];
    puVar6 = *(undefined8 **)(lVar2 + 8);
    *puVar6 = plVar13 + -2;
    plVar13[-2] = lVar2;
    plVar13[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar6;
    *(longlong **)(lVar2 + 8) = plVar13 + -2;
    plVar12 = plVar13;
  }
  else {
    plVar12 = plVar10;
    if ((longlong *)plVar10[3] != plVar7) {
      if (plVar13 == (longlong *)0x0) {
        plVar13 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        DAT_23ed6a4f8 = (longlong *)*plVar13;
        *plVar13 = 1;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      pcVar14 = _PyRuntime_exref;
      plVar13[3] = (longlong)plVar7;
      *plVar7 = *plVar7 + 1;
      lVar2 = *(longlong *)(pcVar14 + 0x1f8);
      *(undefined4 *)(plVar13 + 4) = 0xffffffff;
      *(undefined4 *)((longlong)plVar13 + 0x24) = uVar16;
      lVar2 = *(longlong *)(*(longlong *)(lVar2 + 0x10) + 0x2e8);
      lVar3 = plVar13[-1];
      puVar6 = *(undefined8 **)(lVar2 + 8);
      *puVar6 = plVar13 + -2;
      plVar13[-2] = lVar2;
      plVar13[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar6;
      lVar3 = *plVar10;
      *(longlong **)(lVar2 + 8) = plVar13 + -2;
      plVar13[2] = (longlong)plVar10;
      plVar12 = plVar13;
      if (lVar3 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
    }
  }
  FUN_23e8bba40(plVar7,&DAT_23ec5b14b,plVar1,plVar11);
  if (_DAT_23eeb03a8 == plVar7) {
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      (**(code **)(plVar7[1] + 0x30))(plVar7);
    }
    _DAT_23eeb03a8 = (longlong *)0x0;
  }
  lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar10 = *(longlong **)(lVar2 + 0x28);
  plVar7 = (longlong *)plVar10[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar2 + 0x30);
  *(undefined4 *)(plVar10 + 8) = 0xffffffff;
  if (plVar7 != (longlong *)0x0) {
    plVar10[2] = 0;
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      (**(code **)(plVar7[1] + 0x30))();
    }
  }
  *plVar10 = *plVar10 + -1;
  if (*plVar10 == 0) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  plVar10[0xf] = 0;
  if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,lStack_50,uVar15,plVar12);
  return (code *)0x0;
}

/* ===== 23e10f2e0 telegram.bot_manager:66 ===== */
/* ghidra_name=FUN_23e10f2e0 entry=23e10f2e0 size=2574 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e10f2e0(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined8 *puVar5;
  char cVar6;
  int iVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong *plVar10;
  code *pcVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  
  plVar8 = _DAT_23eeab430;
  plVar1 = (longlong *)*param_3;
  if (_DAT_23eeab430 == (longlong *)0x0) {
LAB_23e10f31a:
    _DAT_23eeab430 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eeab428,DAT_23eeab470,8);
  }
  else {
    lVar2 = *_DAT_23eeab430;
    if (1 < lVar2) {
      *_DAT_23eeab430 = lVar2 + -1;
      goto LAB_23e10f31a;
    }
    if (_DAT_23eeab430[2] != 0) {
      *_DAT_23eeab430 = lVar2 + -1;
      if (lVar2 + -1 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      goto LAB_23e10f31a;
    }
  }
  plVar4 = _DAT_23eeab430;
  lVar2 = *(longlong *)(param_1 + 0x38);
  plVar8 = _DAT_23eeab430 + 9;
  lVar3 = *(longlong *)(lVar2 + 8);
  _DAT_23eeab430[0xf] = lVar3;
  *(longlong **)(lVar2 + 8) = plVar8;
  if ((lVar3 != 0) &&
     (((*(char *)(lVar3 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar3 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar3 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar3 + 0x38))
       ) && (plVar4[0xe] != 0)))) {
    plVar8 = *(longlong **)(lVar3 + 0x28);
    *(longlong **)(plVar4[0xe] + 0x10) = plVar8;
    if (plVar8 != (longlong *)0x0) {
      *plVar8 = *plVar8 + 1;
    }
  }
  *plVar4 = *plVar4 + 1;
  uVar12 = _DAT_23eea98c8;
  *(undefined4 *)(plVar4 + 8) = 0;
  plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,uVar12);
  if (plVar8 != (longlong *)0x0) {
    iVar7 = FUN_23a35f020(plVar8);
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    pcVar11 = _Py_NoneStruct_exref;
    if (iVar7 != -1) {
      if (iVar7 == 0) {
        lVar2 = *(longlong *)(param_1 + 0x38);
        lVar3 = *(longlong *)(lVar2 + 8);
        *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
        plVar8 = *(longlong **)(lVar3 + 0x28);
        plVar4 = (longlong *)plVar8[2];
        *(undefined8 *)(lVar2 + 8) = *(undefined8 *)(lVar3 + 0x30);
        *(undefined4 *)(plVar8 + 8) = 0xffffffff;
        if (plVar4 != (longlong *)0x0) {
          plVar8[2] = 0;
          *plVar4 = *plVar4 + -1;
          if (*plVar4 == 0) {
            (**(code **)(plVar4[1] + 0x30))();
          }
        }
        *plVar8 = *plVar8 + -1;
        if (*plVar8 == 0) {
          (**(code **)(plVar8[1] + 0x30))(plVar8);
        }
        plVar8[0xf] = 0;
        goto LAB_23e10f5a6;
      }
      cVar6 = FUN_23e8d9ac0(plVar1,_DAT_23eea98c8,_Py_FalseStruct_exref);
      if (cVar6 == '\0') {
        uVar12 = *(undefined8 *)(param_1 + 0x60);
        uVar13 = *(undefined8 *)(param_1 + 0x68);
        uVar15 = 0x47;
        plVar8 = *(longlong **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        goto LAB_23e10f622;
      }
      plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eea98d8);
      if (plVar9 == (longlong *)0x0) goto LAB_23e10f908;
      iVar7 = FUN_23a35f020(plVar9);
      lVar2 = *plVar9 + -1;
      if (iVar7 == -1) {
        uVar12 = *(undefined8 *)(param_1 + 0x60);
        uVar13 = *(undefined8 *)(param_1 + 0x68);
        uVar14 = 0x4a;
        uVar15 = 0x4a;
        plVar8 = *(longlong **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *plVar9 = lVar2;
joined_r0x00023e10fbb9:
        if (lVar2 == 0) {
          (**(code **)(plVar9[1] + 0x30))(plVar9);
          uVar15 = uVar14;
        }
      }
      else {
        *plVar9 = lVar2;
        if (lVar2 == 0) {
          (**(code **)(plVar9[1] + 0x30))(plVar9);
        }
        if (iVar7 == 0) {
LAB_23e10f450:
          plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eea98d0);
          if (plVar9 != (longlong *)0x0) {
            iVar7 = FUN_23a35f020(plVar9);
            lVar2 = *plVar9 + -1;
            if (iVar7 == -1) {
              uVar12 = *(undefined8 *)(param_1 + 0x60);
              uVar13 = *(undefined8 *)(param_1 + 0x68);
              uVar14 = 0x4e;
              uVar15 = 0x4e;
              plVar8 = *(longlong **)(param_1 + 0x70);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              *plVar9 = lVar2;
              goto joined_r0x00023e10fbb9;
            }
            *plVar9 = lVar2;
            if (lVar2 == 0) {
              (**(code **)(plVar9[1] + 0x30))(plVar9);
            }
            if (iVar7 == 0) goto LAB_23e10f4a2;
            plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eea98d0);
            if (plVar8 != (longlong *)0x0) {
              *(undefined4 *)(plVar4 + 5) = 0x4e;
              plVar9 = (longlong *)FUN_23e91bfe0(param_1,plVar8,_DAT_23eea9960);
              *plVar8 = *plVar8 + -1;
              if (*plVar8 == 0) {
                (**(code **)(plVar8[1] + 0x30))(plVar8);
              }
              if (plVar9 != (longlong *)0x0) {
                iVar7 = FUN_23a35f020(plVar9);
                lVar2 = *plVar9 + -1;
                if (iVar7 == -1) {
                  uVar12 = *(undefined8 *)(param_1 + 0x60);
                  uVar13 = *(undefined8 *)(param_1 + 0x68);
                  plVar8 = *(longlong **)(param_1 + 0x70);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *plVar9 = lVar2;
                  if (lVar2 == 0) {
                    (**(code **)(plVar9[1] + 0x30))(plVar9);
                  }
                  uVar15 = 0x4e;
                  goto LAB_23e10f622;
                }
                *plVar9 = lVar2;
                if (lVar2 == 0) {
                  (**(code **)(plVar9[1] + 0x30))(plVar9);
                }
                if (iVar7 == 1) {
                  plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eea98d0);
                  if (plVar8 != (longlong *)0x0) {
                    plVar9 = (longlong *)FUN_23e8bc2f0(plVar8,_DAT_23eea9968);
                    *plVar8 = *plVar8 + -1;
                    if (*plVar8 == 0) {
                      (**(code **)(plVar8[1] + 0x30))(plVar8);
                    }
                    lVar2 = _DAT_23eea9970;
                    if (plVar9 != (longlong *)0x0) {
                      *(undefined4 *)(plVar4 + 5) = 0x4f;
                      plVar8 = (longlong *)FUN_23e9186b0(param_1,plVar9,lVar2 + 0x18,_DAT_23eea9978)
                      ;
                      *plVar9 = *plVar9 + -1;
                      if (*plVar9 == 0) {
                        (**(code **)(plVar9[1] + 0x30))(plVar9);
                      }
                      if (plVar8 != (longlong *)0x0) {
                        *plVar8 = *plVar8 + -1;
                        if (*plVar8 == 0) {
                          (**(code **)(plVar8[1] + 0x30))(plVar8);
                        }
                        goto LAB_23e10f4a2;
                      }
                    }
                  }
                  uVar12 = *(undefined8 *)(param_1 + 0x60);
                  uVar13 = *(undefined8 *)(param_1 + 0x68);
                  plVar8 = *(longlong **)(param_1 + 0x70);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  uVar15 = 0x4f;
                }
                else {
LAB_23e10f4a2:
                  lVar2 = _DAT_23eea9980;
                  *(undefined4 *)(plVar4 + 5) = 0x51;
                  plVar8 = (longlong *)
                           FUN_23e915840(param_1,plVar1,DAT_23eea98f8,*(undefined8 *)(lVar2 + 0x18))
                  ;
                  if (plVar8 != (longlong *)0x0) {
                    *plVar8 = *plVar8 + -1;
                    if (*plVar8 == 0) {
                      (**(code **)(plVar8[1] + 0x30))(plVar8);
                    }
                    lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                    plVar8 = *(longlong **)(lVar2 + 0x28);
                    plVar4 = (longlong *)plVar8[2];
                    *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) =
                         *(undefined8 *)(lVar2 + 0x30);
                    *(undefined4 *)(plVar8 + 8) = 0xffffffff;
                    if (plVar4 != (longlong *)0x0) {
                      plVar8[2] = 0;
                      *plVar4 = *plVar4 + -1;
                      if (*plVar4 == 0) {
                        (**(code **)(plVar4[1] + 0x30))();
                      }
                    }
                    *plVar8 = *plVar8 + -1;
                    if (*plVar8 == 0) {
                      (**(code **)(plVar8[1] + 0x30))(plVar8);
                    }
                    plVar8[0xf] = 0;
                    pcVar11 = _Py_NoneStruct_exref;
                    *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
LAB_23e10f5a6:
                    *plVar1 = *plVar1 + -1;
                    if (*plVar1 != 0) {
                      return pcVar11;
                    }
                    (**(code **)(plVar1[1] + 0x30))(plVar1);
                    return pcVar11;
                  }
                  uVar12 = *(undefined8 *)(param_1 + 0x60);
                  uVar13 = *(undefined8 *)(param_1 + 0x68);
                  plVar8 = *(longlong **)(param_1 + 0x70);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  uVar15 = 0x51;
                }
                goto LAB_23e10f622;
              }
            }
          }
          uVar12 = *(undefined8 *)(param_1 + 0x60);
          uVar13 = *(undefined8 *)(param_1 + 0x68);
          plVar8 = *(longlong **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          uVar15 = 0x4e;
          goto LAB_23e10f622;
        }
        plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eea98d8);
        if (plVar8 != (longlong *)0x0) {
          *(undefined4 *)(plVar4 + 5) = 0x4a;
          plVar9 = (longlong *)FUN_23e91bfe0(param_1,plVar8,_DAT_23eea9948);
          *plVar8 = *plVar8 + -1;
          if (*plVar8 == 0) {
            (**(code **)(plVar8[1] + 0x30))(plVar8);
          }
          if (plVar9 != (longlong *)0x0) {
            iVar7 = FUN_23a35f020(plVar9);
            lVar2 = *plVar9 + -1;
            if (iVar7 == -1) {
              uVar12 = *(undefined8 *)(param_1 + 0x60);
              uVar13 = *(undefined8 *)(param_1 + 0x68);
              plVar8 = *(longlong **)(param_1 + 0x70);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              *plVar9 = lVar2;
              if (lVar2 == 0) {
                (**(code **)(plVar9[1] + 0x30))(plVar9);
              }
              uVar15 = 0x4a;
              goto LAB_23e10f622;
            }
            *plVar9 = lVar2;
            if (lVar2 == 0) {
              (**(code **)(plVar9[1] + 0x30))(plVar9);
            }
            if (iVar7 != 1) goto LAB_23e10f450;
            plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eea98d8);
            if (plVar8 != (longlong *)0x0) {
              plVar9 = (longlong *)FUN_23e8bc2f0(plVar8,_DAT_23eea9950);
              *plVar8 = *plVar8 + -1;
              if (*plVar8 == 0) {
                (**(code **)(plVar8[1] + 0x30))(plVar8);
              }
              if (plVar9 != (longlong *)0x0) {
                plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eea98d8);
                if (plVar8 != (longlong *)0x0) {
                  plVar10 = (longlong *)FUN_23e8bc2f0(plVar8,_DAT_23eea9958);
                  *plVar8 = *plVar8 + -1;
                  if (*plVar8 == 0) {
                    (**(code **)(plVar8[1] + 0x30))(plVar8);
                  }
                  if (plVar10 != (longlong *)0x0) {
                    *(undefined4 *)(plVar4 + 5) = 0x4b;
                    plVar8 = (longlong *)FUN_23e914090(param_1,plVar9,plVar10);
                    *plVar9 = *plVar9 + -1;
                    if (*plVar9 == 0) {
                      (**(code **)(plVar9[1] + 0x30))(plVar9);
                    }
                    *plVar10 = *plVar10 + -1;
                    if (*plVar10 == 0) {
                      (**(code **)(plVar10[1] + 0x30))(plVar10);
                    }
                    if (plVar8 != (longlong *)0x0) {
                      *plVar8 = *plVar8 + -1;
                      if (*plVar8 == 0) {
                        (**(code **)(plVar8[1] + 0x30))(plVar8);
                      }
                      goto LAB_23e10f450;
                    }
                    goto LAB_23e10fc48;
                  }
                }
                uVar12 = *(undefined8 *)(param_1 + 0x60);
                uVar13 = *(undefined8 *)(param_1 + 0x68);
                uVar14 = 0x4b;
                uVar15 = 0x4b;
                plVar8 = *(longlong **)(param_1 + 0x70);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                *(undefined8 *)(param_1 + 0x70) = 0;
                *plVar9 = *plVar9 + -1;
                lVar2 = *plVar9;
                goto joined_r0x00023e10fbb9;
              }
            }
LAB_23e10fc48:
            uVar12 = *(undefined8 *)(param_1 + 0x60);
            uVar13 = *(undefined8 *)(param_1 + 0x68);
            uVar15 = 0x4b;
            plVar8 = *(longlong **)(param_1 + 0x70);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            goto LAB_23e10f622;
          }
        }
LAB_23e10f908:
        uVar12 = *(undefined8 *)(param_1 + 0x60);
        uVar13 = *(undefined8 *)(param_1 + 0x68);
        uVar15 = 0x4a;
        plVar8 = *(longlong **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
      }
      goto LAB_23e10f622;
    }
  }
  plVar8 = *(longlong **)(param_1 + 0x70);
  *(undefined8 *)(param_1 + 0x70) = 0;
  uVar15 = 0x44;
  uVar12 = *(undefined8 *)(param_1 + 0x60);
  uVar13 = *(undefined8 *)(param_1 + 0x68);
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e10f622:
  plVar9 = DAT_23ed6a4f8;
  if (plVar8 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar10 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar8 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar8;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      plVar10 = plVar9;
    }
    pcVar11 = _PyRuntime_exref;
    plVar10[2] = 0;
    plVar10[3] = (longlong)plVar4;
    *plVar4 = *plVar4 + 1;
    lVar2 = *(longlong *)(pcVar11 + 0x1f8);
    *(undefined4 *)(plVar10 + 4) = 0xffffffff;
    lVar2 = *(longlong *)(lVar2 + 0x10);
    *(undefined4 *)((longlong)plVar10 + 0x24) = uVar15;
    lVar2 = *(longlong *)(lVar2 + 0x2e8);
    lVar3 = plVar10[-1];
    puVar5 = *(undefined8 **)(lVar2 + 8);
    *puVar5 = plVar10 + -2;
    plVar10[-2] = lVar2;
    plVar10[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar5;
    *(longlong **)(lVar2 + 8) = plVar10 + -2;
  }
  else {
    plVar10 = plVar8;
    if ((longlong *)plVar8[3] != plVar4) {
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar10 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar10 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar10;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        plVar10 = plVar9;
      }
      pcVar11 = _PyRuntime_exref;
      plVar10[3] = (longlong)plVar4;
      *plVar4 = *plVar4 + 1;
      lVar2 = *(longlong *)(pcVar11 + 0x1f8);
      *(undefined4 *)((longlong)plVar10 + 0x24) = uVar15;
      *(undefined4 *)(plVar10 + 4) = 0xffffffff;
      lVar2 = *(longlong *)(*(longlong *)(lVar2 + 0x10) + 0x2e8);
      lVar3 = plVar10[-1];
      puVar5 = *(undefined8 **)(lVar2 + 8);
      *puVar5 = plVar10 + -2;
      plVar10[-2] = lVar2;
      plVar10[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar5;
      lVar3 = *plVar8;
      *(longlong **)(lVar2 + 8) = plVar10 + -2;
      plVar10[2] = (longlong)plVar8;
      if (lVar3 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
    }
  }
  FUN_23e8bba40(plVar4,&DAT_23ec5a08d,plVar1);
  if (_DAT_23eeab430 == plVar4) {
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))(plVar4);
    }
    _DAT_23eeab430 = (longlong *)0x0;
  }
  lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar8 = *(longlong **)(lVar2 + 0x28);
  plVar4 = (longlong *)plVar8[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar2 + 0x30);
  *(undefined4 *)(plVar8 + 8) = 0xffffffff;
  if (plVar4 != (longlong *)0x0) {
    plVar8[2] = 0;
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))();
    }
  }
  *plVar8 = *plVar8 + -1;
  if (*plVar8 == 0) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  plVar8[0xf] = 0;
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,uVar12,uVar13,plVar10);
  return (code *)0x0;
}

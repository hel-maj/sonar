/* ===== 23e81da40 workers.fishing.memory_reeling:MemoryReelingTracker._read_player_right_vec ===== */
/* ghidra_name=FUN_23e81da40 entry=23e81da40 size=2275 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e81da40(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined8 *puVar4;
  longlong *plVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  char cVar8;
  int iVar9;
  longlong lVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong *plVar14;
  code *pcVar15;
  longlong *plVar16;
  undefined4 uVar17;
  undefined8 uStack_68;
  undefined8 uStack_60;
  longlong *plStack_58;
  
  plVar12 = _DAT_23eede790;
  plVar1 = (longlong *)*param_3;
  plVar2 = (longlong *)param_3[1];
  if (_DAT_23eede790 == (longlong *)0x0) {
LAB_23e81da7e:
    _DAT_23eede790 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eede998,DAT_23eedd0f8,0x18);
  }
  else {
    lVar10 = *_DAT_23eede790;
    if (1 < lVar10) {
      *_DAT_23eede790 = lVar10 + -1;
      goto LAB_23e81da7e;
    }
    if (_DAT_23eede790[2] != 0) {
      *_DAT_23eede790 = lVar10 + -1;
      if (lVar10 + -1 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      goto LAB_23e81da7e;
    }
  }
  plVar5 = _DAT_23eede790;
  lVar10 = *(longlong *)(param_1 + 0x38);
  plVar12 = _DAT_23eede790 + 9;
  lVar3 = *(longlong *)(lVar10 + 8);
  _DAT_23eede790[0xf] = lVar3;
  *(longlong **)(lVar10 + 8) = plVar12;
  if ((lVar3 != 0) &&
     (((*(char *)(lVar3 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar3 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar3 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar3 + 0x38))
       ) && (plVar5[0xe] != 0)))) {
    plVar12 = *(longlong **)(lVar3 + 0x28);
    *(longlong **)(plVar5[0xe] + 0x10) = plVar12;
    if (plVar12 != (longlong *)0x0) {
      *plVar12 = *plVar12 + 1;
    }
  }
  *plVar5 = *plVar5 + 1;
  *(undefined4 *)(plVar5 + 8) = 0;
  lVar10 = FUN_23e8dcd80();
  if (lVar10 == 0) {
    FUN_23e915740(param_1,&uStack_68,_DAT_23eedd1a0);
    uVar17 = 0x24c;
    plVar11 = (longlong *)0x0;
    uVar6 = uStack_68;
    plVar12 = plStack_58;
    uVar7 = uStack_60;
    plVar13 = DAT_23ed6a4f8;
    goto joined_r0x00023e81e0b1;
  }
  *(undefined4 *)(plVar5 + 5) = 0x24c;
  plVar11 = (longlong *)FUN_23e91bfe0(param_1,lVar10);
  if (plVar11 == (longlong *)0x0) {
    uVar6 = *(undefined8 *)(param_1 + 0x60);
    plVar12 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar17 = 0x24c;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    uVar7 = *(undefined8 *)(param_1 + 0x68);
    plVar13 = DAT_23ed6a4f8;
    goto joined_r0x00023e81e0b1;
  }
  plVar12 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedd1e0);
  if (plVar12 != (longlong *)0x0) {
    plVar13 = (longlong *)FUN_23e8c6640(plVar11,plVar12);
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      (**(code **)(plVar12[1] + 0x30))(plVar12);
    }
    if (plVar13 != (longlong *)0x0) {
      iVar9 = FUN_23e97c850(plVar13,_DAT_23eedd808);
      *plVar13 = *plVar13 + -1;
      if (*plVar13 == 0) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
      }
      pcVar15 = _Py_NoneStruct_exref;
      if (iVar9 != -1) {
        if (iVar9 == 1) {
          lVar10 = *(longlong *)(param_1 + 0x38);
          lVar3 = *(longlong *)(lVar10 + 8);
          *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
          plVar12 = *(longlong **)(lVar3 + 0x28);
          plVar5 = (longlong *)plVar12[2];
          *(undefined8 *)(lVar10 + 8) = *(undefined8 *)(lVar3 + 0x30);
          *(undefined4 *)(plVar12 + 8) = 0xffffffff;
          if (plVar5 != (longlong *)0x0) {
            plVar12[2] = 0;
            *plVar5 = *plVar5 + -1;
            if (*plVar5 == 0) {
              (**(code **)(plVar5[1] + 0x30))();
            }
          }
          *plVar12 = *plVar12 + -1;
          if (*plVar12 == 0) {
            (**(code **)(plVar12[1] + 0x30))(plVar12);
          }
          plVar12[0xf] = 0;
LAB_23e81ddb7:
          *plVar11 = *plVar11 + -1;
          if (*plVar11 == 0) {
            (**(code **)(plVar11[1] + 0x30))(plVar11);
          }
          *plVar1 = *plVar1 + -1;
          if (*plVar1 == 0) {
            (**(code **)(plVar1[1] + 0x30))(plVar1);
          }
          *plVar2 = *plVar2 + -1;
          if (*plVar2 != 0) {
            return pcVar15;
          }
          (**(code **)(plVar2[1] + 0x30))(plVar2);
          return pcVar15;
        }
        cVar8 = FUN_23e8d9ac0(plVar1,_DAT_23eedd1e0,plVar11);
        if (cVar8 == '\0') {
          uVar6 = *(undefined8 *)(param_1 + 0x60);
          uVar17 = 0x24f;
          plVar12 = *(longlong **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          uVar7 = *(undefined8 *)(param_1 + 0x68);
          plVar13 = DAT_23ed6a4f8;
          goto joined_r0x00023e81e0b1;
        }
        plVar14 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedd1f0);
        uVar6 = _DAT_23eedd810;
        if (plVar14 == (longlong *)0x0) {
LAB_23e81e2a0:
          uVar6 = *(undefined8 *)(param_1 + 0x60);
          uVar17 = 0x250;
          plVar12 = *(longlong **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          uVar7 = *(undefined8 *)(param_1 + 0x68);
          plVar13 = DAT_23ed6a4f8;
          goto joined_r0x00023e81e0b1;
        }
        lVar10 = *(longlong *)(param_1 + 0x10);
        plVar16 = *(longlong **)(lVar10 + 0xe30);
        if (plVar16 == (longlong *)0x0) {
          plVar16 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,4);
        }
        else {
          lVar3 = plVar16[3];
          *(int *)(lVar10 + 0xec4) = *(int *)(lVar10 + 0xec4) + -1;
          *(longlong *)(lVar10 + 0xe30) = lVar3;
          *plVar16 = 1;
        }
        pcVar15 = _PyRuntime_exref;
        plVar16[6] = 0;
        *(undefined1 (*) [16])(plVar16 + 4) = (undefined1  [16])0x0;
        lVar10 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar15 + 0x1f8) + 0x10) + 0x2e8);
        lVar3 = plVar16[-1];
        puVar4 = *(undefined8 **)(lVar10 + 8);
        *puVar4 = plVar16 + -2;
        plVar16[-2] = lVar10;
        plVar16[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar4;
        *(longlong **)(lVar10 + 8) = plVar16 + -2;
        uVar7 = _DAT_23eedd1c8;
        *plVar2 = *plVar2 + 1;
        plVar16[3] = (longlong)plVar2;
        lVar10 = FUN_23e8bc2f0(plVar1,uVar7);
        if (lVar10 != 0) {
          plVar16[4] = lVar10;
          lVar10 = FUN_23e8bc2f0(plVar1,_DAT_23eedd1d0);
          if (lVar10 != 0) {
            plVar16[5] = lVar10;
            lVar10 = FUN_23e8bc2f0(plVar1,_DAT_23eedd1d8);
            if (lVar10 != 0) {
              plVar16[6] = lVar10;
              if (*(code **)(*(longlong *)(PyUnicode_Type_exref + 0x60) + 0x18) == (code *)0x0) {
LAB_23e81e300:
                PyErr_Format(*(undefined8 *)PyExc_TypeError_exref,
                             "unsupported operand type(s) for %%: \'str\' and \'tuple\'");
                *plVar16 = *plVar16 + -1;
                if (*plVar16 == 0) {
                  (**(code **)(plVar16[1] + 0x30))(plVar16);
                }
              }
              else {
                pcVar15 = (code *)(**(code **)(*(longlong *)(PyUnicode_Type_exref + 0x60) + 0x18))
                                            (uVar6,plVar16);
                if (pcVar15 == _Py_NotImplementedStruct_exref) {
                  *(longlong *)pcVar15 = *(longlong *)pcVar15 + -1;
                  if (*(longlong *)pcVar15 == 0) {
                    (**(code **)(*(longlong *)(pcVar15 + 8) + 0x30))(pcVar15);
                  }
                  goto LAB_23e81e300;
                }
                *plVar16 = *plVar16 + -1;
                if (*plVar16 == 0) {
                  (**(code **)(plVar16[1] + 0x30))(plVar16);
                }
                if (pcVar15 != (code *)0x0) {
                  *(undefined4 *)(plVar5 + 5) = 0x250;
                  plVar12 = (longlong *)FUN_23e914090(param_1,plVar14,pcVar15);
                  lVar10 = *plVar14;
                  *plVar14 = lVar10 + -1;
                  if (lVar10 + -1 == 0) {
                    (**(code **)(plVar14[1] + 0x30))(plVar14);
                  }
                  *(longlong *)pcVar15 = *(longlong *)pcVar15 + -1;
                  if (*(longlong *)pcVar15 == 0) {
                    (**(code **)(*(longlong *)(pcVar15 + 8) + 0x30))(pcVar15);
                  }
                  if (plVar12 != (longlong *)0x0) {
                    *plVar12 = *plVar12 + -1;
                    if (*plVar12 == 0) {
                      (**(code **)(plVar12[1] + 0x30))(plVar12);
                    }
                    lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                    plVar12 = *(longlong **)(lVar10 + 0x28);
                    plVar5 = (longlong *)plVar12[2];
                    *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) =
                         *(undefined8 *)(lVar10 + 0x30);
                    *(undefined4 *)(plVar12 + 8) = 0xffffffff;
                    if (plVar5 != (longlong *)0x0) {
                      plVar12[2] = 0;
                      *plVar5 = *plVar5 + -1;
                      if (*plVar5 == 0) {
                        (**(code **)(plVar5[1] + 0x30))();
                      }
                    }
                    *plVar12 = *plVar12 + -1;
                    if (*plVar12 == 0) {
                      (**(code **)(plVar12[1] + 0x30))(plVar12);
                    }
                    plVar12[0xf] = 0;
                    pcVar15 = _Py_NoneStruct_exref;
                    *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
                    goto LAB_23e81ddb7;
                  }
                  goto LAB_23e81e2a0;
                }
              }
              uVar6 = *(undefined8 *)(param_1 + 0x60);
              uVar17 = 0x252;
              uVar7 = *(undefined8 *)(param_1 + 0x68);
              plVar12 = *(longlong **)(param_1 + 0x70);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              lVar10 = *plVar14;
              *(undefined8 *)(param_1 + 0x70) = 0;
              *plVar14 = lVar10 + -1;
              plVar13 = DAT_23ed6a4f8;
              if (lVar10 + -1 == 0) {
                (**(code **)(plVar14[1] + 0x30))();
                uVar17 = 0x252;
                plVar13 = DAT_23ed6a4f8;
              }
              goto joined_r0x00023e81e0b1;
            }
          }
        }
        uVar6 = *(undefined8 *)(param_1 + 0x60);
        uVar7 = *(undefined8 *)(param_1 + 0x68);
        plVar12 = *(longlong **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        lVar10 = *plVar14;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *plVar14 = lVar10 + -1;
        if (lVar10 + -1 == 0) {
          (**(code **)(plVar14[1] + 0x30))();
        }
        *plVar16 = *plVar16 + -1;
        uVar17 = 0x252;
        plVar13 = DAT_23ed6a4f8;
        if (*plVar16 == 0) {
          (**(code **)(plVar16[1] + 0x30))(plVar16);
          uVar17 = 0x252;
          plVar13 = DAT_23ed6a4f8;
        }
        goto joined_r0x00023e81e0b1;
      }
    }
  }
  uVar6 = *(undefined8 *)(param_1 + 0x60);
  plVar12 = *(longlong **)(param_1 + 0x70);
  *(undefined8 *)(param_1 + 0x70) = 0;
  uVar17 = 0x24d;
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  uVar7 = *(undefined8 *)(param_1 + 0x68);
  plVar13 = DAT_23ed6a4f8;
joined_r0x00023e81e0b1:
  DAT_23ed6a4f8 = plVar13;
  if (plVar12 == (longlong *)0x0) {
    if (plVar13 == (longlong *)0x0) {
      plVar14 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar13;
      *plVar13 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      plVar14 = plVar13;
    }
    pcVar15 = _PyRuntime_exref;
    plVar14[2] = 0;
    plVar14[3] = (longlong)plVar5;
    *plVar5 = *plVar5 + 1;
    lVar10 = *(longlong *)(pcVar15 + 0x1f8);
    *(undefined4 *)((longlong)plVar14 + 0x24) = uVar17;
    lVar10 = *(longlong *)(lVar10 + 0x10);
    *(undefined4 *)(plVar14 + 4) = 0xffffffff;
    lVar10 = *(longlong *)(lVar10 + 0x2e8);
    lVar3 = plVar14[-1];
    puVar4 = *(undefined8 **)(lVar10 + 8);
    *puVar4 = plVar14 + -2;
    plVar14[-2] = lVar10;
    plVar14[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar4;
    *(longlong **)(lVar10 + 8) = plVar14 + -2;
  }
  else {
    plVar14 = plVar12;
    if ((longlong *)plVar12[3] != plVar5) {
      if (plVar13 == (longlong *)0x0) {
        plVar14 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        DAT_23ed6a4f8 = (longlong *)*plVar13;
        *plVar13 = 1;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        plVar14 = plVar13;
      }
      pcVar15 = _PyRuntime_exref;
      plVar14[3] = (longlong)plVar5;
      *plVar5 = *plVar5 + 1;
      lVar10 = *(longlong *)(pcVar15 + 0x1f8);
      *(undefined4 *)((longlong)plVar14 + 0x24) = uVar17;
      *(undefined4 *)(plVar14 + 4) = 0xffffffff;
      lVar10 = *(longlong *)(*(longlong *)(lVar10 + 0x10) + 0x2e8);
      lVar3 = plVar14[-1];
      puVar4 = *(undefined8 **)(lVar10 + 8);
      *puVar4 = plVar14 + -2;
      plVar14[-2] = lVar10;
      plVar14[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar4;
      lVar3 = *plVar12;
      *(longlong **)(lVar10 + 8) = plVar14 + -2;
      plVar14[2] = (longlong)plVar12;
      if (lVar3 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
    }
  }
  FUN_23e8bba40(plVar5,&DAT_23ec5e2be,plVar1,plVar2,plVar11);
  if (_DAT_23eede790 == plVar5) {
    *plVar5 = *plVar5 + -1;
    if (*plVar5 == 0) {
      (**(code **)(plVar5[1] + 0x30))(plVar5);
    }
    _DAT_23eede790 = (longlong *)0x0;
  }
  lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar12 = *(longlong **)(lVar10 + 0x28);
  plVar5 = (longlong *)plVar12[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar10 + 0x30);
  *(undefined4 *)(plVar12 + 8) = 0xffffffff;
  if (plVar5 != (longlong *)0x0) {
    plVar12[2] = 0;
    *plVar5 = *plVar5 + -1;
    if (*plVar5 == 0) {
      (**(code **)(plVar5[1] + 0x30))();
    }
  }
  *plVar12 = *plVar12 + -1;
  if (*plVar12 == 0) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  plVar12[0xf] = 0;
  if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  FUN_23a33aa70(param_1,uVar6,uVar7,plVar14);
  return (code *)0x0;
}

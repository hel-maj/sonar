/* ===== 23e8186f0 workers.fishing.memory_reeling:MemoryReelingTracker._find_replay_interface_global ===== */
/* ghidra_name=FUN_23e8186f0 entry=23e8186f0 size=1988 */

longlong * FUN_23e8186f0(longlong param_1,undefined8 param_2,longlong *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong lVar4;
  longlong *plVar5;
  undefined8 uVar6;
  undefined8 *puVar7;
  longlong *plVar8;
  code *pcVar9;
  int iVar10;
  longlong *plVar11;
  longlong *plVar12;
  undefined4 uVar13;
  longlong *plVar14;
  longlong unaff_R13;
  longlong *unaff_R14;
  undefined8 *local_78;
  undefined8 local_68;
  longlong *plStack_60;
  
  plVar14 = DAT_23eede808;
  plVar1 = (longlong *)*param_3;
  plVar2 = (longlong *)param_3[1];
  if (DAT_23eede808 == (longlong *)0x0) {
LAB_23e81873b:
    DAT_23eede808 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eede9e8,DAT_23eedd0f8,0x28);
  }
  else {
    lVar3 = *DAT_23eede808;
    if (1 < lVar3) {
      *DAT_23eede808 = lVar3 + -1;
      goto LAB_23e81873b;
    }
    if (DAT_23eede808[2] != 0) {
      *DAT_23eede808 = lVar3 + -1;
      if (lVar3 + -1 == 0) {
        (**(code **)(plVar14[1] + 0x30))(plVar14);
      }
      goto LAB_23e81873b;
    }
  }
  plVar5 = DAT_23eede808;
  lVar3 = *(longlong *)(param_1 + 0x38);
  plVar14 = DAT_23eede808 + 9;
  lVar4 = *(longlong *)(lVar3 + 8);
  DAT_23eede808[0xf] = lVar4;
  *(longlong **)(lVar3 + 8) = plVar14;
  if ((lVar4 != 0) &&
     (((*(char *)(lVar4 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar4 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar4 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar4 + 0x38))
       ) && (plVar5[0xe] != 0)))) {
    plVar14 = *(longlong **)(lVar4 + 0x28);
    *(longlong **)(plVar5[0xe] + 0x10) = plVar14;
    if (plVar14 != (longlong *)0x0) {
      *plVar14 = *plVar14 + 1;
    }
  }
  *plVar5 = *plVar5 + 1;
  plVar14 = &DAT_23ed6ccc0;
  *(undefined4 *)(plVar5 + 8) = 0;
  plVar11 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23eedd2b8);
  uVar6 = DAT_23eedd650;
  if ((plVar11 == (longlong *)0x0) || (unaff_R13 = *plVar11, unaff_R13 == 0)) goto LAB_23e818cb0;
  plVar12 = (longlong *)PyNumber_Long(plVar2);
  plVar11 = (longlong *)0x0;
  if (plVar12 == (longlong *)0x0) {
LAB_23e818ad0:
    local_78 = *(undefined8 **)(param_1 + 0x60);
    unaff_R13 = *(longlong *)(param_1 + 0x68);
    unaff_R14 = (longlong *)0x0;
    uVar13 = 0x1d5;
    plVar12 = *(longlong **)(param_1 + 0x70);
LAB_23e818ae9:
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar8 = DAT_23ed6a4f8;
    if (plVar12 == (longlong *)0x0) {
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar14 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar14 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar14;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        plVar14 = plVar8;
      }
      pcVar9 = _PyRuntime_exref;
      plVar14[3] = (longlong)plVar5;
      plVar14[2] = 0;
      *plVar5 = *plVar5 + 1;
      lVar3 = *(longlong *)(pcVar9 + 0x1f8);
      *(undefined4 *)((longlong)plVar14 + 0x24) = uVar13;
      *(undefined4 *)(plVar14 + 4) = 0xffffffff;
      lVar3 = *(longlong *)(*(longlong *)(lVar3 + 0x10) + 0x2e8);
      lVar4 = plVar14[-1];
      puVar7 = *(undefined8 **)(lVar3 + 8);
      *puVar7 = plVar14 + -2;
      plVar14[-2] = lVar3;
      plVar14[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar7;
      *(longlong **)(lVar3 + 8) = plVar14 + -2;
    }
    else {
      plVar14 = plVar12;
      if ((longlong *)plVar12[3] != plVar5) {
        if (DAT_23ed6a4f8 == (longlong *)0x0) {
          plVar14 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
        }
        else {
          plVar14 = (longlong *)*DAT_23ed6a4f8;
          *DAT_23ed6a4f8 = 1;
          DAT_23ed6a4f8 = plVar14;
          DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
          plVar14 = plVar8;
        }
        pcVar9 = _PyRuntime_exref;
        plVar14[3] = (longlong)plVar5;
        *plVar5 = *plVar5 + 1;
        lVar3 = *(longlong *)(pcVar9 + 0x1f8);
        *(undefined4 *)((longlong)plVar14 + 0x24) = uVar13;
        *(undefined4 *)(plVar14 + 4) = 0xffffffff;
        lVar3 = *(longlong *)(*(longlong *)(lVar3 + 0x10) + 0x2e8);
        lVar4 = plVar14[-1];
        puVar7 = *(undefined8 **)(lVar3 + 8);
        *puVar7 = plVar14 + -2;
        plVar14[-2] = lVar3;
        plVar14[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar7;
        lVar4 = *plVar12;
        *(longlong **)(lVar3 + 8) = plVar14 + -2;
        plVar14[2] = (longlong)plVar12;
        if (lVar4 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
      }
    }
    FUN_23e8bba40(plVar5,"ooNoo",plVar1,plVar2,0,plVar11,unaff_R14);
    if (DAT_23eede808 == plVar5) {
      *plVar5 = *plVar5 + -1;
      if (*plVar5 == 0) {
        (**(code **)(plVar5[1] + 0x30))(plVar5);
      }
      DAT_23eede808 = (longlong *)0x0;
    }
    lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
    plVar5 = *(longlong **)(lVar3 + 0x28);
    plVar12 = (longlong *)plVar5[2];
    *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar3 + 0x30);
    *(undefined4 *)(plVar5 + 8) = 0xffffffff;
    if (plVar12 != (longlong *)0x0) {
      plVar5[2] = 0;
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) {
        (**(code **)(plVar12[1] + 0x30))();
      }
    }
    *plVar5 = *plVar5 + -1;
    if (*plVar5 == 0) {
      (**(code **)(plVar5[1] + 0x30))(plVar5);
    }
    plVar5[0xf] = 0;
    if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
    }
    if ((unaff_R14 == (longlong *)0x0) || (*unaff_R14 = *unaff_R14 + -1, *unaff_R14 != 0))
    goto LAB_23e818c49;
  }
  else {
    unaff_R14 = (longlong *)FUN_23e8c5d90(plVar12,DAT_23eedd658);
    *plVar12 = *plVar12 + -1;
    if (*plVar12 != 0) {
      if (unaff_R14 != (longlong *)0x0) goto LAB_23e81883a;
LAB_23e818a83:
      local_78 = *(undefined8 **)(param_1 + 0x60);
      unaff_R13 = *(longlong *)(param_1 + 0x68);
      plVar11 = (longlong *)0x0;
      uVar13 = 0x1d4;
      plVar12 = *(longlong **)(param_1 + 0x70);
      goto LAB_23e818ae9;
    }
    (**(code **)(plVar12[1] + 0x30))(plVar12);
    if (unaff_R14 == (longlong *)0x0) goto LAB_23e818a83;
LAB_23e81883a:
    *(undefined4 *)(plVar5 + 5) = 0x1d5;
    local_78 = &local_68;
    local_68 = uVar6;
    plStack_60 = unaff_R14;
    plVar11 = (longlong *)FUN_23e94ed00(param_1,unaff_R13,local_78);
    *unaff_R14 = *unaff_R14 + -1;
    if (*unaff_R14 == 0) {
      (**(code **)(unaff_R14[1] + 0x30))(unaff_R14);
    }
    if (plVar11 == (longlong *)0x0) goto LAB_23e818ad0;
    plVar12 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23eedd4c0);
    uVar6 = DAT_23eedd660;
    if (plVar12 != (longlong *)0x0) {
      lVar3 = *plVar12;
      plVar14 = (longlong *)0x0;
      if (lVar3 != 0) {
        plVar14 = (longlong *)PyNumber_Long(plVar2);
        unaff_R14 = (longlong *)0x0;
        if (plVar14 == (longlong *)0x0) {
LAB_23e818da0:
          local_78 = *(undefined8 **)(param_1 + 0x60);
          unaff_R13 = *(longlong *)(param_1 + 0x68);
          uVar13 = 0x1d6;
          plVar12 = *(longlong **)(param_1 + 0x70);
        }
        else {
          plVar12 = (longlong *)FUN_23e8bf9b0(plVar14,DAT_23eedd658);
          *plVar14 = *plVar14 + -1;
          if (*plVar14 == 0) {
            (**(code **)(plVar14[1] + 0x30))(plVar14);
          }
          if (plVar12 == (longlong *)0x0) {
            local_78 = *(undefined8 **)(param_1 + 0x60);
            unaff_R13 = *(longlong *)(param_1 + 0x68);
            unaff_R14 = (longlong *)0x0;
            uVar13 = 0x1d4;
            plVar12 = *(longlong **)(param_1 + 0x70);
          }
          else {
            *(undefined4 *)(plVar5 + 5) = 0x1d6;
            local_68 = uVar6;
            plStack_60 = plVar12;
            unaff_R14 = (longlong *)FUN_23e94ed00(param_1,lVar3,local_78);
            *plVar12 = *plVar12 + -1;
            if (*plVar12 == 0) {
              (**(code **)(plVar12[1] + 0x30))(plVar12);
            }
            if (unaff_R14 == (longlong *)0x0) goto LAB_23e818da0;
            iVar10 = FUN_23e97b4b0(unaff_R14,plVar11);
            plVar14 = DAT_23eedd668;
            if (iVar10 != -1) {
              lVar3 = *(longlong *)(param_1 + 0x38);
              plVar5 = *(longlong **)(*(longlong *)(lVar3 + 8) + 0x28);
              uVar6 = *(undefined8 *)(*(longlong *)(lVar3 + 8) + 0x30);
              plVar12 = (longlong *)plVar5[2];
              if (iVar10 == 1) {
                *DAT_23eedd668 = *DAT_23eedd668 + 1;
                *(undefined8 *)(lVar3 + 8) = uVar6;
                *(undefined4 *)(plVar5 + 8) = 0xffffffff;
                if (plVar12 != (longlong *)0x0) {
                  plVar5[2] = 0;
                  *plVar12 = *plVar12 + -1;
                  if (*plVar12 == 0) {
                    (**(code **)(plVar12[1] + 0x30))();
                  }
                }
                *plVar5 = *plVar5 + -1;
                if (*plVar5 == 0) {
                  (**(code **)(plVar5[1] + 0x30))(plVar5);
                }
                plVar5[0xf] = 0;
              }
              else {
                *(undefined8 *)(lVar3 + 8) = uVar6;
                *(undefined4 *)(plVar5 + 8) = 0xffffffff;
                if (plVar12 != (longlong *)0x0) {
                  plVar5[2] = 0;
                  *plVar12 = *plVar12 + -1;
                  if (*plVar12 == 0) {
                    (**(code **)(plVar12[1] + 0x30))();
                  }
                }
                *plVar5 = *plVar5 + -1;
                if (*plVar5 == 0) {
                  (**(code **)(plVar5[1] + 0x30))(plVar5);
                }
                plVar5[0xf] = 0;
                lVar3 = *(longlong *)(param_1 + 0x10);
                plVar14 = *(longlong **)(lVar3 + 0xe20);
                if (plVar14 == (longlong *)0x0) {
                  plVar14 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
                }
                else {
                  lVar4 = plVar14[3];
                  *(int *)(lVar3 + 0xebc) = *(int *)(lVar3 + 0xebc) + -1;
                  *(longlong *)(lVar3 + 0xe20) = lVar4;
                  *plVar14 = 1;
                }
                lVar3 = *(longlong *)
                         (*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
                lVar4 = plVar14[-1];
                puVar7 = *(undefined8 **)(lVar3 + 8);
                *puVar7 = plVar14 + -2;
                plVar14[-2] = lVar3;
                plVar14[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar7;
                *(longlong **)(lVar3 + 8) = plVar14 + -2;
                *plVar11 = *plVar11 + 1;
                plVar14[3] = (longlong)plVar11;
                *unaff_R14 = *unaff_R14 + 1;
                plVar14[4] = (longlong)unaff_R14;
              }
              *plVar11 = *plVar11 + -1;
              if (*plVar11 == 0) {
                (**(code **)(plVar11[1] + 0x30))(plVar11);
              }
              *unaff_R14 = *unaff_R14 + -1;
              if (*unaff_R14 == 0) {
                (**(code **)(unaff_R14[1] + 0x30))(unaff_R14);
              }
              lVar3 = *plVar1;
              *plVar1 = lVar3 + -1;
              if (lVar3 + -1 == 0) {
                (**(code **)(plVar1[1] + 0x30))(plVar1);
              }
              *plVar2 = *plVar2 + -1;
              if (*plVar2 != 0) {
                return plVar14;
              }
              (**(code **)(plVar2[1] + 0x30))(plVar2);
              return plVar14;
            }
            local_78 = *(undefined8 **)(param_1 + 0x60);
            unaff_R13 = *(longlong *)(param_1 + 0x68);
            uVar13 = 0x1d7;
            plVar12 = *(longlong **)(param_1 + 0x70);
          }
        }
        goto LAB_23e818ae9;
      }
    }
LAB_23e818cb0:
    PyErr_PrintEx(0);
    Py_Exit(1);
  }
  (**(code **)(unaff_R14[1] + 0x30))(unaff_R14);
LAB_23e818c49:
  lVar3 = *plVar1;
  *plVar1 = lVar3 + -1;
  if (lVar3 + -1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  FUN_23a33aa70(param_1,local_78,unaff_R13,plVar14);
  return (longlong *)0x0;
}

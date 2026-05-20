/* ===== 23e81ccf0 workers.fishing.memory_reeling:MemoryReelingTracker._find_fish_addr_replay ===== */
/* ghidra_name=FUN_23e81ccf0 entry=23e81ccf0 size=3284 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong * FUN_23e81ccf0(longlong param_1,longlong param_2,longlong *param_3)

{
  undefined1 *puVar1;
  undefined1 (*pauVar2) [16];
  code *pcVar3;
  longlong *plVar4;
  undefined8 *puVar5;
  char cVar6;
  int iVar7;
  longlong *plVar8;
  longlong lVar9;
  longlong lVar10;
  undefined8 uVar11;
  undefined8 *puVar12;
  longlong *plVar13;
  undefined4 uVar14;
  longlong *plVar15;
  bool bVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  
  plVar8 = _DAT_23eede7c8;
  pauVar2 = *(undefined1 (**) [16])(param_2 + 0x90);
  if (*(int *)(param_2 + 0x78) == 1) {
    if (param_3 == (longlong *)0x0) goto LAB_23e81d635;
    *param_3 = *param_3 + -1;
    if (*param_3 == 0) {
      (**(code **)(param_3[1] + 0x30))(param_3);
    }
    lVar9 = *(longlong *)(param_1 + 0x10);
    if ((((*(int *)(*(longlong *)(lVar9 + 0x28) + 0x160) == 0) && (*(int *)(lVar9 + 0x78) == 0)) ||
        (iVar7 = Py_MakePendingCalls(), -1 < iVar7)) ||
       (lVar10 = *(longlong *)(param_1 + 0x60), lVar10 == 0)) {
      if (*(int *)(lVar9 + 0x68) != 0) {
        PyEval_SaveThread();
        PyEval_AcquireThread(param_1);
      }
      plVar8 = *(longlong **)(param_1 + 0x90);
      if (plVar8 != (longlong *)0x0) {
        plVar15 = *(longlong **)(param_1 + 0x60);
        plVar13 = *(longlong **)(param_1 + 0x68);
        *(undefined8 *)(param_1 + 0x90) = 0;
        plVar4 = *(longlong **)(param_1 + 0x70);
        *(longlong **)(param_1 + 0x60) = plVar8;
        *plVar8 = *plVar8 + 1;
        *(undefined8 *)(param_1 + 0x68) = 0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
          (**(code **)(plVar15[1] + 0x30))();
        }
        if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
          (**(code **)(plVar13[1] + 0x30))(plVar13);
        }
        if ((plVar4 == (longlong *)0x0) || (*plVar4 = *plVar4 + -1, *plVar4 != 0))
        goto LAB_23e81d635;
        (**(code **)(plVar4[1] + 0x30))(plVar4);
        lVar10 = *(longlong *)(param_1 + 0x60);
        goto LAB_23e81d639;
      }
      goto LAB_23e81cdfe;
    }
LAB_23e81d639:
    *(longlong *)(pauVar2[4] + 8) = lVar10;
    uVar14 = 0x1f1;
    *(undefined8 *)pauVar2[5] = *(undefined8 *)(param_1 + 0x68);
    *(undefined8 *)(pauVar2[5] + 8) = *(undefined8 *)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    uVar17 = *(undefined8 *)(pauVar2[4] + 8);
    uVar18 = *(undefined8 *)pauVar2[5];
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined **)pauVar2[4] = &DAT_23ec5e4ef;
    uVar11 = *(undefined8 *)(pauVar2[5] + 8);
  }
  else {
    *(undefined8 *)pauVar2[4] = 0;
    *pauVar2 = (undefined1  [16])0x0;
    pauVar2[1] = (undefined1  [16])0x0;
    pauVar2[2] = (undefined1  [16])0x0;
    pauVar2[3] = (undefined1  [16])0x0;
    *(undefined8 *)(pauVar2[5] + 8) = 0;
    *(undefined4 *)pauVar2[6] = 0;
    *(undefined1 (*) [16])(pauVar2[4] + 8) = (undefined1  [16])0x0;
    if (plVar8 == (longlong *)0x0) {
LAB_23e81cd6b:
      plVar8 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eedea30,DAT_23eedd0f8,0x20);
      lVar9 = *plVar8;
      _DAT_23eede7c8 = plVar8;
    }
    else {
      lVar9 = *plVar8;
      if (1 < lVar9) {
        *plVar8 = lVar9 + -1;
        goto LAB_23e81cd6b;
      }
      if (plVar8[2] != 0) {
        *plVar8 = lVar9 + -1;
        if (lVar9 + -1 == 0) {
          (**(code **)(plVar8[1] + 0x30))();
        }
        goto LAB_23e81cd6b;
      }
    }
    lVar10 = *(longlong *)(param_1 + 0x38);
    *(longlong **)(param_2 + 0x50) = plVar8;
    *plVar8 = lVar9 + 1;
    lVar9 = *(longlong *)(lVar10 + 8);
    plVar8[7] = param_2;
    *(undefined4 *)(plVar8 + 8) = 0;
    plVar8[0xf] = lVar9;
    *(longlong **)(lVar10 + 8) = plVar8 + 9;
    if ((lVar9 != 0) &&
       (((*(char *)(lVar9 + 0x45) == '\x01' ||
         ((ulonglong)
          (*(longlong *)(lVar9 + 0x20) + 0xb8 +
          (longlong)*(int *)(*(longlong *)(lVar9 + 0x20) + 0xa8) * 2) <=
          *(ulonglong *)(lVar9 + 0x38))) && (plVar8[0xe] != 0)))) {
      plVar15 = *(longlong **)(lVar9 + 0x28);
      *(longlong **)(plVar8[0xe] + 0x10) = plVar15;
      if (plVar15 != (longlong *)0x0) {
        *plVar15 = *plVar15 + 1;
      }
    }
    plVar8 = *(longlong **)(param_1 + 0x138);
    *(longlong **)(param_2 + 0x68) = plVar8;
    if (plVar8 != (longlong *)0x0) {
      *plVar8 = *plVar8 + 1;
    }
LAB_23e81cdfe:
    lVar9 = *(longlong *)(*(longlong *)(*(longlong *)(param_2 + 0xa0) + 0x10) + 8);
    pcVar3 = *(code **)(lVar9 + 0xe0);
    if (pcVar3 == (code *)0x0) {
      PyErr_Format(*(undefined8 *)PyExc_TypeError_exref,"\'%s\' object is not an iterator",
                   *(undefined8 *)(lVar9 + 0x18));
LAB_23e81d61b:
      cVar6 = FUN_23a3591a0(param_1,*(undefined8 *)PyExc_StopIteration_exref);
      if (cVar6 != '\0') {
        plVar8 = *(longlong **)(param_2 + 0x68);
        if (plVar8 != (longlong *)0x0) {
          *(undefined8 *)(param_2 + 0x68) = 0;
          *plVar8 = *plVar8 + -1;
          if (*plVar8 == 0) {
            (**(code **)(plVar8[1] + 0x30))();
          }
        }
        plVar8 = *(longlong **)pauVar2[2];
        if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
          (**(code **)(plVar8[1] + 0x30))();
        }
        plVar8 = *(longlong **)*pauVar2;
        *(undefined8 *)pauVar2[2] = 0;
        if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
          (**(code **)(plVar8[1] + 0x30))();
        }
        plVar8 = *(longlong **)(*pauVar2 + 8);
        *(undefined8 *)*pauVar2 = 0;
        if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
          (**(code **)(plVar8[1] + 0x30))();
        }
        *(undefined8 *)(*pauVar2 + 8) = 0;
        return (longlong *)0x0;
      }
LAB_23e81d635:
      lVar10 = *(longlong *)(param_1 + 0x60);
      goto LAB_23e81d639;
    }
    lVar9 = (*pcVar3)();
    if (lVar9 == 0) goto LAB_23e81d61b;
    plVar8 = *(longlong **)pauVar2[2];
    *(longlong *)pauVar2[2] = lVar9;
    if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
      lVar9 = *(longlong *)pauVar2[2];
    }
    lVar9 = FUN_23a388310(lVar9);
    if (lVar9 == 0) {
      uVar14 = 0x1f1;
      *(undefined8 *)(pauVar2[4] + 8) = *(undefined8 *)(param_1 + 0x60);
      *(undefined8 *)pauVar2[5] = *(undefined8 *)(param_1 + 0x68);
      *(undefined8 *)(pauVar2[5] + 8) = *(undefined8 *)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      uVar17 = *(undefined8 *)(pauVar2[4] + 8);
      uVar18 = *(undefined8 *)pauVar2[5];
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined **)pauVar2[4] = &DAT_23ec5e4ef;
      uVar11 = *(undefined8 *)(pauVar2[5] + 8);
LAB_23e81d152:
      plVar8 = *(longlong **)(pauVar2[2] + 8);
      *(undefined4 *)pauVar2[10] = uVar14;
      *(undefined4 *)pauVar2[6] = 0;
      *(undefined8 *)(pauVar2[9] + 8) = uVar11;
      *(undefined8 *)(pauVar2[5] + 8) = 0;
      *(undefined8 *)(pauVar2[8] + 8) = uVar17;
      *(undefined8 *)pauVar2[9] = uVar18;
      *(undefined1 (*) [16])(pauVar2[4] + 8) = (undefined1  [16])0x0;
      if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
        (**(code **)(plVar8[1] + 0x30))();
      }
      plVar8 = *(longlong **)pauVar2[3];
      *(undefined8 *)(pauVar2[2] + 8) = 0;
      if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
        (**(code **)(plVar8[1] + 0x30))();
      }
      uVar11 = *(undefined8 *)(pauVar2[9] + 8);
      uVar17 = *(undefined8 *)(pauVar2[8] + 8);
      uVar18 = *(undefined8 *)pauVar2[9];
      *(undefined8 *)pauVar2[3] = 0;
      uVar14 = *(undefined4 *)pauVar2[10];
      *(undefined8 *)(pauVar2[5] + 8) = uVar11;
      *(undefined8 *)(pauVar2[4] + 8) = uVar17;
      *(undefined8 *)pauVar2[5] = uVar18;
    }
    else {
      plVar8 = *(longlong **)(pauVar2[3] + 8);
      *(longlong *)(pauVar2[3] + 8) = lVar9;
      if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
        lVar9 = *(longlong *)(pauVar2[3] + 8);
      }
      puVar1 = pauVar2[4] + 8;
      lVar9 = (**(code **)(*(longlong *)(lVar9 + 8) + 0xe0))();
      if ((lVar9 == 0) && (lVar9 = FUN_23a3c1b70(param_1,puVar1,0,2), lVar9 == 0)) {
LAB_23e81d0e5:
        uVar17 = *(undefined8 *)(pauVar2[4] + 8);
        uVar18 = *(undefined8 *)pauVar2[5];
        plVar8 = *(longlong **)(pauVar2[3] + 8);
        *(undefined **)pauVar2[4] = &DAT_23ec5e4ef;
        uVar11 = *(undefined8 *)(pauVar2[5] + 8);
        uVar14 = 0x1f1;
        *(undefined4 *)pauVar2[8] = 0x1f1;
        *(undefined4 *)pauVar2[6] = 0;
        *(undefined8 *)(pauVar2[7] + 8) = uVar11;
        *(undefined8 *)(pauVar2[5] + 8) = 0;
        *(undefined8 *)(pauVar2[6] + 8) = uVar17;
        *(undefined8 *)pauVar2[7] = uVar18;
        *(undefined1 (*) [16])(pauVar2[4] + 8) = (undefined1  [16])0x0;
        *plVar8 = *plVar8 + -1;
        if (*plVar8 == 0) {
          (**(code **)(plVar8[1] + 0x30))();
          uVar14 = *(undefined4 *)pauVar2[8];
        }
        uVar11 = *(undefined8 *)(pauVar2[7] + 8);
        uVar17 = *(undefined8 *)(pauVar2[6] + 8);
        uVar18 = *(undefined8 *)pauVar2[7];
        *(undefined8 *)(pauVar2[3] + 8) = 0;
        *(undefined8 *)(pauVar2[5] + 8) = uVar11;
        *(undefined8 *)(pauVar2[4] + 8) = uVar17;
        *(undefined8 *)pauVar2[5] = uVar18;
        goto LAB_23e81d152;
      }
      plVar8 = *(longlong **)(pauVar2[2] + 8);
      *(longlong *)(pauVar2[2] + 8) = lVar9;
      if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
        (**(code **)(plVar8[1] + 0x30))();
      }
      lVar9 = (**(code **)(*(longlong *)(*(longlong *)(pauVar2[3] + 8) + 8) + 0xe0))();
      if ((lVar9 == 0) && (lVar9 = FUN_23a3c1b70(param_1,puVar1,1,2), lVar9 == 0))
      goto LAB_23e81d0e5;
      plVar8 = *(longlong **)pauVar2[3];
      *(longlong *)pauVar2[3] = lVar9;
      if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
        (**(code **)(plVar8[1] + 0x30))();
      }
      cVar6 = FUN_23a3884a0(param_1,puVar1,*(undefined8 *)(pauVar2[3] + 8),2);
      pauVar2[6][4] = cVar6;
      if (cVar6 == '\0') goto LAB_23e81d0e5;
      plVar8 = *(longlong **)(pauVar2[3] + 8);
      *plVar8 = *plVar8 + -1;
      if (*plVar8 == 0) {
        (**(code **)(plVar8[1] + 0x30))();
      }
      plVar8 = *(longlong **)(pauVar2[2] + 8);
      plVar15 = *(longlong **)*pauVar2;
      *(undefined8 *)(pauVar2[3] + 8) = 0;
      lVar9 = *plVar8;
      *(longlong **)*pauVar2 = plVar8;
      *plVar8 = lVar9 + 1;
      if (plVar15 == (longlong *)0x0) {
LAB_23e81d3a7:
        *plVar8 = lVar9;
        if (lVar9 == 0) {
          (**(code **)(plVar8[1] + 0x30))();
        }
      }
      else {
        *plVar15 = *plVar15 + -1;
        if (*plVar15 != 0) {
LAB_23e81d3a0:
          lVar9 = *plVar8 + -1;
          goto LAB_23e81d3a7;
        }
        (**(code **)(plVar15[1] + 0x30))(plVar15);
        plVar8 = *(longlong **)(pauVar2[2] + 8);
        if (plVar8 != (longlong *)0x0) goto LAB_23e81d3a0;
      }
      plVar8 = *(longlong **)pauVar2[3];
      plVar15 = *(longlong **)(*pauVar2 + 8);
      *(undefined8 *)(pauVar2[2] + 8) = 0;
      lVar9 = *plVar8;
      *(longlong **)(*pauVar2 + 8) = plVar8;
      *plVar8 = lVar9 + 1;
      if (plVar15 == (longlong *)0x0) {
LAB_23e81d3c7:
        *plVar8 = lVar9;
        if (lVar9 == 0) {
          (**(code **)(plVar8[1] + 0x30))();
        }
      }
      else {
        *plVar15 = *plVar15 + -1;
        if (*plVar15 != 0) {
LAB_23e81d3c0:
          lVar9 = *plVar8 + -1;
          goto LAB_23e81d3c7;
        }
        (**(code **)(plVar15[1] + 0x30))(plVar15);
        plVar8 = *(longlong **)pauVar2[3];
        if (plVar8 != (longlong *)0x0) goto LAB_23e81d3c0;
      }
      lVar9 = *(longlong *)(param_2 + 0xa8);
      *(undefined8 *)pauVar2[3] = 0;
      plVar8 = *(longlong **)(lVar9 + 0x10);
      if (plVar8 == (longlong *)0x0) {
        if (((*(byte *)(_DAT_23eedd6e8 + 0x20) & 0x40) == 0) ||
           (lVar9 = _DAT_23eedd6e8 + 0x30, (*(byte *)(_DAT_23eedd6e8 + 0x20) & 0x20) == 0)) {
          lVar9 = *(longlong *)(_DAT_23eedd6e8 + 0x38);
        }
        uVar11 = PyUnicode_FromFormat
                           ("cannot access free variable \'%s\' where it is not associated with a value in enclosing scope"
                            ,lVar9);
        pcVar3 = *(code **)PyExc_NameError_exref;
        *(longlong *)pcVar3 = *(longlong *)pcVar3 + 1;
        bVar16 = pcVar3 != _Py_NoneStruct_exref;
        *(undefined8 *)(pauVar2[5] + 8) = 0;
        *(code **)(pauVar2[4] + 8) = pcVar3;
        *(undefined8 *)pauVar2[5] = uVar11;
        if (bVar16) {
          FUN_23e91b1b0(param_1,puVar1,pauVar2 + 5,pauVar2[5] + 8);
          uVar11 = *(undefined8 *)pauVar2[5];
        }
        FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),uVar11);
      }
      else {
        plVar15 = *(longlong **)(pauVar2[1] + 8);
        *(longlong **)(pauVar2[1] + 8) = plVar8;
        *plVar8 = *plVar8 + 1;
        if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
          (**(code **)(plVar15[1] + 0x30))();
          plVar8 = *(longlong **)(pauVar2[1] + 8);
        }
        lVar9 = FUN_23e8cfe60(*(undefined8 *)*pauVar2,plVar8);
        if (lVar9 != 0) {
          plVar8 = *(longlong **)pauVar2[1];
          *(longlong *)pauVar2[1] = lVar9;
          if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
            (**(code **)(plVar8[1] + 0x30))(plVar8);
            lVar9 = *(longlong *)pauVar2[1];
          }
          iVar7 = FUN_23a35f020(lVar9);
          *(int *)(pauVar2[10] + 4) = iVar7;
          if (iVar7 != -1) {
            if (iVar7 == 0) {
              plVar8 = *(longlong **)pauVar2[1];
              *plVar8 = *plVar8 + 1;
LAB_23e81d00f:
              plVar15 = *(longlong **)(pauVar2[1] + 8);
              *plVar15 = *plVar15 + -1;
              if (*plVar15 == 0) {
                (**(code **)(plVar15[1] + 0x30))();
              }
              plVar15 = *(longlong **)pauVar2[1];
              *(undefined8 *)(pauVar2[1] + 8) = 0;
              *plVar15 = *plVar15 + -1;
              if (*plVar15 == 0) {
                (**(code **)(plVar15[1] + 0x30))();
              }
              *(undefined8 *)pauVar2[1] = 0;
              *(undefined4 *)(param_2 + 0x78) = 1;
              return plVar8;
            }
            plVar8 = (longlong *)
                     FUN_23e8d09c0(*(undefined8 *)(pauVar2[1] + 8),*(undefined8 *)(*pauVar2 + 8));
            if (plVar8 != (longlong *)0x0) goto LAB_23e81d00f;
          }
        }
        *(undefined8 *)(pauVar2[4] + 8) = *(undefined8 *)(param_1 + 0x60);
        *(undefined8 *)pauVar2[5] = *(undefined8 *)(param_1 + 0x68);
        *(undefined8 *)(pauVar2[5] + 8) = *(undefined8 *)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      }
      uVar17 = *(undefined8 *)(pauVar2[4] + 8);
      uVar18 = *(undefined8 *)pauVar2[5];
      plVar8 = *(longlong **)(pauVar2[1] + 8);
      *(undefined **)pauVar2[4] = &DAT_23ec5e4ef;
      uVar11 = *(undefined8 *)(pauVar2[5] + 8);
      *(undefined4 *)pauVar2[0xc] = 0x1f1;
      *(undefined4 *)pauVar2[6] = 0;
      *(undefined8 *)(pauVar2[0xb] + 8) = uVar11;
      *(undefined8 *)(pauVar2[5] + 8) = 0;
      *(undefined8 *)(pauVar2[10] + 8) = uVar17;
      *(undefined8 *)pauVar2[0xb] = uVar18;
      *(undefined1 (*) [16])(pauVar2[4] + 8) = (undefined1  [16])0x0;
      if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
        (**(code **)(plVar8[1] + 0x30))();
      }
      plVar8 = *(longlong **)pauVar2[1];
      *(undefined8 *)(pauVar2[1] + 8) = 0;
      if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
        (**(code **)(plVar8[1] + 0x30))();
      }
      uVar17 = *(undefined8 *)(pauVar2[10] + 8);
      uVar18 = *(undefined8 *)pauVar2[0xb];
      uVar11 = *(undefined8 *)(pauVar2[0xb] + 8);
      *(undefined8 *)pauVar2[1] = 0;
      uVar14 = *(undefined4 *)pauVar2[0xc];
      *(undefined8 *)(pauVar2[5] + 8) = uVar11;
      *(undefined8 *)(pauVar2[4] + 8) = uVar17;
      *(undefined8 *)pauVar2[5] = uVar18;
    }
  }
  plVar8 = *(longlong **)pauVar2[2];
  *(undefined4 *)pauVar2[0xe] = uVar14;
  *(undefined4 *)pauVar2[6] = 0;
  *(undefined8 *)(pauVar2[0xd] + 8) = uVar11;
  *(undefined8 *)(pauVar2[5] + 8) = 0;
  *(undefined8 *)(pauVar2[0xc] + 8) = uVar17;
  *(undefined8 *)pauVar2[0xd] = uVar18;
  *(undefined1 (*) [16])(pauVar2[4] + 8) = (undefined1  [16])0x0;
  if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
    (**(code **)(plVar8[1] + 0x30))();
    uVar14 = *(undefined4 *)pauVar2[0xe];
  }
  uVar11 = *(undefined8 *)(pauVar2[0xc] + 8);
  uVar17 = *(undefined8 *)pauVar2[0xd];
  *(undefined4 *)pauVar2[6] = uVar14;
  *(undefined8 *)pauVar2[2] = 0;
  *(undefined8 *)(pauVar2[4] + 8) = uVar11;
  uVar18 = *(undefined8 *)(pauVar2[0xd] + 8);
  *(undefined8 *)pauVar2[5] = uVar17;
  *(undefined8 *)(pauVar2[5] + 8) = uVar18;
  cVar6 = FUN_23a35d720(param_1,uVar11);
  puVar12 = DAT_23ed6a4f8;
  if (cVar6 != '\0') goto LAB_23e81d2af;
  plVar8 = *(longlong **)(pauVar2[5] + 8);
  iVar7 = *(int *)pauVar2[6];
  plVar15 = *(longlong **)(param_2 + 0x50);
  if (plVar8 == (longlong *)0x0) {
    if (iVar7 == 0) {
      iVar7 = (int)plVar15[5];
    }
    if (DAT_23ed6a4f8 == (undefined8 *)0x0) {
      puVar12 = (undefined8 *)FUN_23a33a530(PyTraceBack_Type_exref);
      plVar8 = *(longlong **)(pauVar2[5] + 8);
    }
    else {
      puVar5 = (undefined8 *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = puVar5;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      plVar8 = (longlong *)0x0;
    }
    pcVar3 = _PyRuntime_exref;
    puVar12[2] = 0;
    puVar12[3] = plVar15;
    *plVar15 = *plVar15 + 1;
    lVar9 = *(longlong *)(pcVar3 + 0x1f8);
    *(undefined4 *)(puVar12 + 4) = 0xffffffff;
    lVar9 = *(longlong *)(lVar9 + 0x10);
    *(int *)((longlong)puVar12 + 0x24) = iVar7;
    lVar9 = *(longlong *)(lVar9 + 0x2e8);
    uVar11 = puVar12[-1];
    puVar5 = *(undefined8 **)(lVar9 + 8);
    *puVar5 = puVar12 + -2;
    puVar12[-2] = lVar9;
    puVar12[-1] = (ulonglong)((uint)uVar11 & 3) | (ulonglong)puVar5;
    *(undefined8 **)(lVar9 + 8) = puVar12 + -2;
    if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
LAB_23e81d5f0:
    *(undefined8 **)(pauVar2[5] + 8) = puVar12;
    plVar15 = *(longlong **)(param_2 + 0x50);
  }
  else if ((iVar7 != 0) && ((longlong *)plVar8[3] != plVar15)) {
    if (DAT_23ed6a4f8 == (undefined8 *)0x0) {
      puVar12 = (undefined8 *)FUN_23a33a530(PyTraceBack_Type_exref);
      plVar13 = *(longlong **)(pauVar2[5] + 8);
    }
    else {
      puVar5 = (undefined8 *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = puVar5;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      plVar13 = plVar8;
    }
    pcVar3 = _PyRuntime_exref;
    puVar12[3] = plVar15;
    *plVar15 = *plVar15 + 1;
    lVar9 = *(longlong *)(pcVar3 + 0x1f8);
    *(undefined4 *)(puVar12 + 4) = 0xffffffff;
    *(int *)((longlong)puVar12 + 0x24) = iVar7;
    lVar9 = *(longlong *)(*(longlong *)(lVar9 + 0x10) + 0x2e8);
    uVar11 = puVar12[-1];
    puVar5 = *(undefined8 **)(lVar9 + 8);
    *puVar5 = puVar12 + -2;
    puVar12[-2] = lVar9;
    puVar12[-1] = (ulonglong)((uint)uVar11 & 3) | (ulonglong)puVar5;
    *(undefined8 **)(lVar9 + 8) = puVar12 + -2;
    puVar12[2] = plVar8;
    *plVar8 = *plVar8 + 1;
    if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
      (**(code **)(plVar13[1] + 0x30))();
    }
    goto LAB_23e81d5f0;
  }
  FUN_23e8bba40(plVar15,*(undefined8 *)pauVar2[4],0,*(undefined8 *)*pauVar2,
                *(undefined8 *)(*pauVar2 + 8),*(undefined8 *)(param_2 + 0xa8));
  plVar8 = _DAT_23eede7c8;
  if (*(longlong **)(param_2 + 0x50) == _DAT_23eede7c8) {
    *_DAT_23eede7c8 = *_DAT_23eede7c8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))();
    }
    _DAT_23eede7c8 = (longlong *)0x0;
  }
LAB_23e81d2af:
  plVar8 = *(longlong **)(param_2 + 0x68);
  if (plVar8 != (longlong *)0x0) {
    *(undefined8 *)(param_2 + 0x68) = 0;
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))();
    }
  }
  uVar14 = *(undefined4 *)pauVar2[6];
  uVar17 = *(undefined8 *)(pauVar2[4] + 8);
  uVar18 = *(undefined8 *)pauVar2[5];
  *(undefined4 *)pauVar2[6] = 0;
  plVar8 = *(longlong **)*pauVar2;
  *(undefined1 (*) [16])(pauVar2[4] + 8) = (undefined1  [16])0x0;
  *(undefined4 *)pauVar2[0x10] = uVar14;
  uVar11 = *(undefined8 *)(pauVar2[5] + 8);
  *(undefined8 *)(pauVar2[0xe] + 8) = uVar17;
  *(undefined8 *)pauVar2[0xf] = uVar18;
  *(undefined8 *)(pauVar2[0xf] + 8) = uVar11;
  *(undefined8 *)(pauVar2[5] + 8) = 0;
  if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
    (**(code **)(plVar8[1] + 0x30))();
  }
  plVar8 = *(longlong **)(*pauVar2 + 8);
  *(undefined8 *)*pauVar2 = 0;
  if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
    (**(code **)(plVar8[1] + 0x30))();
  }
  uVar14 = *(undefined4 *)pauVar2[0x10];
  uVar11 = *(undefined8 *)(pauVar2[0xe] + 8);
  uVar17 = *(undefined8 *)pauVar2[0xf];
  *(undefined8 *)(*pauVar2 + 8) = 0;
  *(undefined8 *)(pauVar2[5] + 8) = *(undefined8 *)(pauVar2[0xf] + 8);
  *(undefined4 *)pauVar2[6] = uVar14;
  *(undefined8 *)(pauVar2[4] + 8) = uVar11;
  *(undefined8 *)pauVar2[5] = uVar17;
  FUN_23a33aa70(param_1,*(undefined8 *)(pauVar2[4] + 8),*(undefined8 *)pauVar2[5]);
  return (longlong *)0x0;
}
